/**************************** INTELLECTUAL PROPERTY RIGHTS ****************************/
/*                                                                                    */
/*                           Copyright (c) 2025 Terminus LLC                          */
/*                                                                                    */
/*                                All Rights Reserved.                                */
/*                                                                                    */
/*          Use of this source code is governed by LICENSE in the repo root.          */
/*                                                                                    */
/**************************** INTELLECTUAL PROPERTY RIGHTS ****************************/
/**
 * @file    UTM.cpp
 * @author  Marvin Smith
 * @date    01/09/2025
 */
#include <terminus/coord/types/UTM.hpp>

namespace tmns::coord {

/****************************************/
/*          Create Coordinate           */
/****************************************/
UTM UTM::create( int    grid_zone,
                 double easting_meters,
                 double northing_meters,
                 double elevation_meters,
                 Datum  datum )
{
    return UTM( grid_zone,
                easting_meters,
                northing_meters,
                elevation_meters,
                datum );
}

/****************************************/
/*             Constructor              */
/****************************************/
UTM::UTM( int    grid_zone,
          double easting_meters,
          double northing_meters,
          double elevation_meters,
          Datum  datum )
    : m_data { math::ToVector3<double>( easting_meters,
                                        northing_meters,
                                        elevation_meters ) },
      m_grid_zone { grid_zone },
      m_datum { datum }
{
}

} // End of tmns::coord namespace
