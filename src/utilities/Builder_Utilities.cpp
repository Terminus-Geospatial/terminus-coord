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
 * @file    Builder_Utilities.cpp
 * @author  Marvin Smith
 * @date    01/08/2025
 */
#include <terminus/coord/utilities/Builder_Utilities.hpp>

// Terminus Libraries
#include <terminus/coord/utilities/EPSG_Utilities.hpp>
#include <terminus/core/error/ErrorCategory.hpp>

// C++ Standard Libraries
#include <string>

namespace tmns::coord::build {

/*************************************/
/*      Determine Coordinate-Type    */
/*************************************/
Result<CoordinateType> find_coordinate_type( const std::map<KeyType,std::string>& kvp )
{
    // Check if coordinate type specified
    auto ctval = kvp.find( KeyType::COORDINATE_TYPE );
    if( ctval != kvp.end() ){
        return tmns::outcome::ok<CoordinateType>( to_coordinate_type( ctval->second ) );
    }

    // Get the EPSG code
    auto epsg_val = kvp.find( KeyType::EPSG_CODE );
    if( epsg_val != kvp.end() ){

        // Use the EPSG code to determine coordinate type
        try {
            auto cval = from_epsg( std::stoi( epsg_val->second ) );
        } catch( std::exception& e ){
            return tmns::outcome::fail( core::error::ErrorCode::CONVERSION_ERROR,
                                        "Unable to convert EPSG_CODE value (",
                                        epsg_val->second, ") to CoordinateType." );
        }
    }


}

} // End of tmns::coord::build namespace
