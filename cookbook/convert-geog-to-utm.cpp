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
 * @file    convert-geog-to-utm.cpp
 * @author  Marvin Smith
 * @date    01/09/2025
 */

// Terminus Libraries
#include <terminus/coord.hpp>
#include <terminus/log.hpp>

namespace crd = tmns::coord;

int main( int argc, char* argv[] )
{

    // Create a Geographic Coordinate
    auto lla_coord = crd::Geographic::create( -104.5, 38.9, 123.0 );

    auto xform = crd::Transformer::create( crd::CoordinateType::UTM,
                                           { crd::Param( crd::KeyType::GRID_ZONE, 13 ) } );
    
    if( xform.has_error() ){
        tmns::log::error( "Problem creating Transformer instance: ", xform.error().message() );
        return 1;
    }
    
    // Convert a single coordinate to UTM
    auto utm_coord = xform.value().convert( lla_coord );


}