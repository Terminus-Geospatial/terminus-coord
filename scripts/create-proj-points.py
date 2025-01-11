#!/usr/bin/env python3
#*************************** INTELLECTUAL PROPERTY RIGHTS ***************************#
#                                                                                    #
#                           Copyright (c) 2025 Terminus LLC                          #
#                                                                                    #
#                                All Rights Reserved.                                #
#                                                                                    #
#          Use of this source code is governed by LICENSE in the repo root.          #
#                                                                                    #
#*************************** INTELLECTUAL PROPERTY RIGHTS ***************************#
#
#  file:    create-proj-points.py
#  author:  Marvin Smith
#  date:    01/08/2025
#
#  This application creates the CSV files used in the Proj portion of the
#  tmns-coord-test-battery application.  This application uses pyproj to perform a large
#  set of random projections to create a useful set of conversions. 
# 
#  Currently supported tests:
#  - geographic to geographic conversions:  
#    - Datum conversions. 
#  - geographic to UTM conversions
#  - UTM to Geographic conversions
#  - UTM to UTM conversions
#
#  Datums supported:  NAD27, NAD83, WGS72, WGS84
#

#  Python Libraries
import argparse
from enum import Enum
import json
import logging
import random
import time

#  PyProj
from pyproj import CRS, Transformer

#  Others
import requests
import tqdm

base_url = 'https://epqs.nationalmap.gov/v1/json?units=Meters&wkid=4326&includeDate=True'
#x=-104&y=39&'

class Datum(Enum):
    NAD_27 = 'NAD_27'
    NAD_83 = 'NAD_83'
    WGS_72 = 'WGS_72'
    WGS_84 = 'WGS_84'

    @staticmethod
    def to_proj_str( d ):
        if d == Datum.NAD_27:
            return 'NAD27'
        if d == Datum.NAD_83:
            return 'NAD83'
        if d == Datum.WGS_72:
            return 'WGS72'
        if d == Datum.WGS_84:
            return 'WGS84'
        return None
    
    def to_epsg( datum ):
        if datum == Datum.NAD_27:
            return 4267
        if datum == Datum.NAD_83:
            return 4269
        if datum == Datum.WGS_72:
            return 4984
        if datum == Datum.WGS_84:
            return 4326
        

def parse_command_line():

    parser = argparse.ArgumentParser( description = 'Create test data using Proj' )

    parser.add_argument( '-g','--grid-zone',
                         dest='grid_zones',
                         type=int,
                         action='append',
                         default=[],
                         help='Specify grid zones to create points for' )

    parser.add_argument( '-p','--points-per-zone',
                         dest='points_per_zone',
                         type=int,
                         default = 10,
                         help='Number of points to create per grid zone.' )
    
    parser.add_argument( '--polar-points',
                         dest = 'num_polar_points',
                         default = 20,
                         help = 'Number of polar points to use for each pole in UPS conversions.' )
    
    parser.add_argument( '-v',
                         dest = 'log_level',
                         default = logging.INFO,
                         action = 'store_const',
                         const = logging.DEBUG,
                         help = 'Use verbose logging.' )

    return parser.parse_args()

def get_utm_bounds( grid_zone ):

    max_lon = grid_zone * 6 - 180
    min_lon = max_lon - 6

    return (min_lon, max_lon)

def get_utm_bounds_lut():

    bounds = {}
    for gz in range( 1, 61 ):
        bounds[gz] = get_utm_bounds( gz )

    return bounds

def get_elevation( logger, lat, lon ):
    '''
    Query the USGS National Map - Elevation Point Query Service
    https://apps.nationalmap.gov/epqs/

    Note that because the Earth is mostly water, or over Russia, this will likely fail.  Therefore it'll return 0.
    '''

    url = base_url + f'&x={lon:.4f}&y={lat:.4f}'
    logger.debug( f'url request: {url}' )
    
    response = requests.get( url )
    time.sleep( 0.2 )

    if response.status_code == 200:
        logging.debug( f'Response: {response.text}' )
        if 'Invalid or missing' in response.text:
            pass
        elif 'Failed cloud operation' in response.text:
            pass
        else:
            logging.debug(response.text)
            try:
                resp_data = json.loads( response.text )
                return float( resp_data['value'] )
            except Exception as e:
                pass
    else:
        logging.error('Failed to retrieve')

    return 0

def create_nonpolar_wgs84_geographic_coordinates( logger, utm_catalog, grid_zone, num_points ):

    #  The grid zone defines the longitudinal bounds
    bounds = utm_catalog[grid_zone]

    points = { Datum.NAD_27: [],
               Datum.NAD_83: [],
               Datum.WGS_72: [],
               Datum.WGS_84: [] }

    #  Iterate over each point
    for p in range( 0, num_points ):

        #  Note that above 84 and below -80, we use Universal Polar Stereographic
        lat = random.uniform( -80, 84 )
        lon = random.uniform( bounds[0], bounds[1] )

        elev = get_elevation( logger, lat, lon )

        points[Datum.WGS_84].append( [lat,lon,elev] )

    return points

def create_polar_wgs84_geographic_coordinates( logger, num_points ):

    points = []

    #  For northern latitudes, use 84 N
    for p in range( 0, num_points ):

        lat  = random.uniform( 84, 90 )
        lon  = random.uniform( -180, 180 )
        elev = get_elevation( logger, lat, lon )

        points.append( [lat,lon,elev] )
    
    for p in range( 0, num_points ):

        lat = random.uniform( -90, -80 )
        lon = random.uniform( -180, 180 )
        elev = get_elevation( logger, lat, lon )

        points.append( [lat,lon,elev] )

    return points

def convert_geographic_to_geographic( coord, in_datum, out_datum ):

    crs_in  = CRS.from_epsg( Datum.to_epsg( in_datum ) )
    crs_out = CRS.from_epsg( Datum.to_epsg( out_datum ) )

    xform = Transformer.from_crs( crs_from=crs_in, crs_to=crs_out )

    return xform.transform( coord[0], coord[1], coord[2] )

def write_geographic_to_geographic_single( fout, in_crs, out_crs, coord_list ):

    #  Iterate over each coordinate
    for idx in range( 0, len( coord_list[in_crs ] ) ):

        #  Get the coordinates
        crd_in  = coord_list[in_crs][idx]
        crd_out = coord_list[out_crs][idx]

        #  Write to CSV
        fout.write( f'{Datum.to_epsg(in_crs)},{Datum.to_proj_str(in_crs)},{crd_in[1]:.6f},{crd_in[0]:.6f},{crd_in[2]:.2f},')
        fout.write( f'{Datum.to_epsg(out_crs)},{Datum.to_proj_str(out_crs)},{crd_out[1]:.6f},{crd_out[0]:.6f},{crd_out[2]:.2f}')
        fout.write('\n') #  DO NOT FORGET NEWLINE!

def write_geographic_to_geographic_single( fout, in_crs, out_crs, coord_list ):

    #  Iterate over each coordinate
    for idx in range( 0, len( coord_list[in_crs ] ) ):

        #  Get the coordinates
        crd_in  = coord_list[in_crs][idx]
        crd_out = coord_list[out_crs][idx]

        #  Write to CSV
        fout.write( f'{Datum.to_epsg(in_crs)},{Datum.to_proj_str(in_crs)},{crd_in[1]:.6f},{crd_in[0]:.6f},{crd_in[2]:.2f},')
        fout.write( f'{Datum.to_epsg(out_crs)},{Datum.to_proj_str(out_crs)},{crd_out[1]:.6f},{crd_out[0]:.6f},{crd_out[2]:.2f}')
        fout.write('\n') #  DO NOT FORGET NEWLINE!

def write_geographic_to_geographic( fout, coord_list ):

    write_geographic_to_geographic_single( fout, Datum.NAD_27, Datum.NAD_83, coord_list )
    write_geographic_to_geographic_single( fout, Datum.NAD_27, Datum.WGS_72, coord_list )
    write_geographic_to_geographic_single( fout, Datum.NAD_27, Datum.WGS_84, coord_list )

    write_geographic_to_geographic_single( fout, Datum.NAD_83, Datum.NAD_27, coord_list )
    write_geographic_to_geographic_single( fout, Datum.NAD_83, Datum.WGS_72, coord_list )
    write_geographic_to_geographic_single( fout, Datum.NAD_83, Datum.WGS_84, coord_list )

    write_geographic_to_geographic_single( fout, Datum.WGS_72, Datum.NAD_27, coord_list )
    write_geographic_to_geographic_single( fout, Datum.WGS_72, Datum.NAD_83, coord_list )
    write_geographic_to_geographic_single( fout, Datum.WGS_72, Datum.WGS_84, coord_list )

    write_geographic_to_geographic_single( fout, Datum.WGS_84, Datum.NAD_27, coord_list )
    write_geographic_to_geographic_single( fout, Datum.WGS_84, Datum.NAD_83, coord_list )
    write_geographic_to_geographic_single( fout, Datum.WGS_84, Datum.WGS_72, coord_list )

def write_geographic_to_utm( fout, coord_list ):

    write_geographic_to_utm_single( fout, Datum.NAD_27, Datum.NAD_83, coord_list )
    write_geographic_to_utm_single( fout, Datum.NAD_27, Datum.WGS_72, coord_list )
    write_geographic_to_utm_single( fout, Datum.NAD_27, Datum.WGS_84, coord_list )

    write_geographic_to_utm_single( fout, Datum.NAD_83, Datum.NAD_27, coord_list )
    write_geographic_to_utm_single( fout, Datum.NAD_83, Datum.WGS_72, coord_list )
    write_geographic_to_utm_single( fout, Datum.NAD_83, Datum.WGS_84, coord_list )

    write_geographic_to_utm_single( fout, Datum.WGS_72, Datum.NAD_27, coord_list )
    write_geographic_to_utm_single( fout, Datum.WGS_72, Datum.NAD_83, coord_list )
    write_geographic_to_utm_single( fout, Datum.WGS_72, Datum.WGS_84, coord_list )

    write_geographic_to_utm_single( fout, Datum.WGS_84, Datum.NAD_27, coord_list )
    write_geographic_to_utm_single( fout, Datum.WGS_84, Datum.NAD_83, coord_list )
    write_geographic_to_utm_single( fout, Datum.WGS_84, Datum.WGS_72, coord_list )

def main():

    #  Parse Command-Line
    config = parse_command_line()

    #  Setup logger
    logging.basicConfig( level = config.log_level )
    logger = logging.getLogger( 'create-proj-points' )
    
    #  Verify Grid-Zones to use.
    grid_zones = config.grid_zones
    if len( grid_zones ) <= 0:
        logger.info( 'No grid zones specified. Adding all.' )
        grid_zones = [x for x in range( 1, 61 ) ]

    #  Create catalog of UTM bounds in WGS84
    utm_bounds_lut = get_utm_bounds_lut()
    
    #  Setup list of datums
    datums = ['NAD27','NAD83','WGS72','WGS84']

    #  Setup CSV file handles
    g2g_fout = open( 'proj_geographic_to_geographic.csv', 'w' )
    g2g_fout.write( 'epsg_in,datum_in,lon_deg_in,lat_deg_in,elev_m_in,epsg_out,datum_out,lon_deg_out,lat_deg_out,elev_m_out\n')

    g2u_fout = open( 'proj_geographic_2_utm.csv', 'w' )
    g2u_fout.write( 'epsg_in,epsg_out,datum,lon_deg,lat_deg,elev_m,datum,gz,easting_m,northing_m,elev_m\n' )

    u2g_fout = open( 'proj_utm_2_geographic.csv', 'w' )
    u2g_fout.write( 'epsg_in,epsg_out,datum,gz,easting_m,northing_m,elev_m,datumlon_deg,lat_deg,elev_m\n' )

    u2u_fout = open( 'proj_utm_to_utm.csv', 'w' )
    u2u_fout.write( 'epsg_in,epsg_out,gz,easting_m,northing_m,elev_m,lon_deg,lat_deg,elev_m,gz,easting_m,northing_m,elev_m,lon_deg,lat_deg,elev_m\n' )

    #  Iterate over each grid zone (WGS84)
    for gz in tqdm.tqdm(grid_zones):
        logger.debug( f'Processing WGS84 Grid-Zone {gz}' )

        #  Create a list of WGS-84 geographic coordinates
        ref_coords = create_nonpolar_wgs84_geographic_coordinates( logger      = logger,
                                                                   utm_catalog = utm_bounds_lut, 
                                                                   grid_zone   = gz,
                                                                   num_points  = config.points_per_zone )
        for coord in ref_coords[Datum.WGS_84]:
            ref_coords[Datum.NAD_27].append( convert_geographic_to_geographic( coord, Datum.WGS_84, Datum.NAD_27 ) )
            ref_coords[Datum.NAD_83].append( convert_geographic_to_geographic( coord, Datum.WGS_84, Datum.NAD_27 ) )
            ref_coords[Datum.WGS_72].append( convert_geographic_to_geographic( coord, Datum.WGS_84, Datum.NAD_27 ) )
        
        output_str  = f'Non-Polar Coordinates: Grid-Zone: {gz}\n'
        output_str += f'                       WGS-84: {len(ref_coords[Datum.WGS_84])}\n'
        output_str += f'                       WGS-72: {len(ref_coords[Datum.WGS_72])}\n'
        output_str += f'                       NAD-27: {len(ref_coords[Datum.NAD_27])}\n'
        output_str += f'                       NAD-83: {len(ref_coords[Datum.NAD_83])}'
        logger.debug( output_str )

        ups_ref_coords = create_polar_wgs84_geographic_coordinates( logger     = logger,
                                                                    num_points = config.num_polar_points )
        logger.debug( f'Polar Coordinates:\n                       WGS-84: {len(ups_ref_coords)}' )

        #  Perform Geographic to Geographic Transforms
        write_geographic_to_geographic( g2g_fout, ref_coords )

        #  Perform Geographic to UTM Transforms
        write_geographic_to_utm( g2u_fout, ref_coords )
        

        #  Write Entries
        #g2u_fout.write( f'{epsg_geo},{epsg_utm},{lon:.4f},{lat:.4f},{elev:.2f},{gz},{utm[0]:.2f},{utm[1]:.4f},{elev:.2f}\n')
        #u2g_fout.write( f'{epsg_utm},{epsg_geo},{gz},{utm[0]:.2f},{utm[1]:.2f},{elev:.2f},{lon:.4f},{lat:.4f},{elev:.2f}\n')

if __name__ == '__main__':
    main()

