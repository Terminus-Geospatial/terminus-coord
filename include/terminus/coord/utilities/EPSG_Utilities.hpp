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
#pragma once

// Terminus Libraries
#include <terminus/coord/types/CoordinateType.hpp>
#include <terminus/core/error/ErrorCategory.hpp>

// C++ Standard Libraries
#include <map>

namespace tmns::coord {

/**
 * Default EPSG to Coordinate-Type lookup table.  You can override this with your own implementation if 
 * you choose.
 */
static constexpr std::map<int,CoordinateType> EPSG_TO_CTYPE_LUT() {
    return std::map<int,CoordinateType>( { { 4326, CoordinateType::GEOGRAPHIC } } );
}

/**
 * Extract the CoordinateType from an ESPG code.
 */
Result<CoordinateType> from_epsg( int epsg, std::map<int,CoordinateType> lut = EPSG_TO_CTYPE_LUT() );

} // End of tmns::coord namespace
