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
 * @file    Geographic.cpp
 * @author  Marvin Smith
 * @date    01/09/2025
 */
#include <terminus/coord/types/Geographic.hpp>


namespace tmns::coord {

/****************************************/
/*          Create Coordinate           */
/****************************************/
Geographic Geographic::create( double lon_degrees,
                               double lat_degrees,
                               double elev_meters,
                               Datum  datum )
{
    return Geographic( lon_degrees,
                       lat_degrees,
                       elev_meters,
                       datum );
}

/********************************/
/*          Coordinate          */
/********************************/
Geographic::Geographic( double lon_degrees,
                        double lat_degrees,
                        double elev_meters,
                        Datum  datum )
    : m_data { math::ToVector3<double>( lon_degrees,
                                        lat_degrees,
                                        elev_meters ) },
      m_datum { datum }
{
}


} // End of tmns::coord namespace
