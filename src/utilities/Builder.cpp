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
 * @file    Builder.cpp
 * @author  Marvin Smith
 * @date    01/09/2025
 */
#include <terminus/coord/utilities/Builder.hpp>

// Terminus Libraries
#include <terminus/coord/utilities/Builder_Utilities.hpp>
#include <terminus/coord/utilities/EPSG_Utilities.hpp>

// Internal Libraries
#include "string_utilities.hpp"

namespace tmns::coord {

/******************************************************/
/*      Create Coordinate from Key/Value Pair Map     */
/******************************************************/
Result<Coordinate> Builder::create_from_kvp_map( std::map<KeyType,std::string> kvp )
{
    // Get the coordinate type
    auto ctype = build::find_coordinate_type( kvp );
    if( ctype.has_error() ){
        return tmns::outcome::fail( ctype.error() );
    }

    // Create return coordinate
    Coordinate coord( ctype.value() );
    
    return tmns::outcome::ok<Coordinate>( coord );
}

} // End of tmns::coord namespace
