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
 * @file    EPSG_Utilities.hpp
 * @author  Marvin Smith
 * @date    01/09/2025
 */
#include <terminus/coord/utilities/EPSG_Utilities.hpp>


namespace tmns::coord {

/********************************************/
/*      EPSG Code to Coordinate Type        */
/********************************************/
Result<CoordinateType> from_epsg( int epsg, std::map<int,CoordinateType> lut )
{
    if( lut.count( epsg ) > 0 ){
        return tmns::outcome::ok<CoordinateType>( lut.find( epsg )->second );
    }
    return tmns::outcome::fail( core::error::ErrorCode::NOT_FOUND,
                                "No CoordinateType registered for EPSG code: ", epsg );
}

} // End of tmns::coord namespace
