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
 * @file    CoordinateType.hpp
 * @author  Marvin Smith
 * @date    01/08/2025
 */
#pragma once

// C++ Standard Libraries
#include <string>

namespace tmns::coord {

/**
 * @enum CoordinateType
 */
enum class CoordinateType
{
    UNKNOWN    = 0 /**< This should be an error condition. */,
    BASE       = 1 /**< This should be an error condition. */,
    CARTESIAN  = 2 /**< Standard Projection-Less 3-dimensional coordinate */,
    GEOGRAPHIC = 3 /**< Spherical coordinate */,
    GEOCENTRIC = 4 /**< Earth-Centric */,
    ECEF       = 4 /**< Earth-Centered, Earth-Fixed */,
    SPHERICAL  = 5 /**< Spherical Coordinate System. */,
    TRANS_MERC = 6 /**< Transverse Mercator */,
    UTM        = 7 /**< Universal Transverse Mercator */,
};// End of CoordinateType enumeration

/**
 * Convert the CoordinateType to string
 */
std::string to_string( CoordinateType tp );

/**
 * Convert string to CoordinateType
 */
CoordinateType to_coordinate_type( const std::string& tp );

} // End of tmns::coord namespace
