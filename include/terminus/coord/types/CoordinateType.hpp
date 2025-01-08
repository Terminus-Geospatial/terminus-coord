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
enum CoordinateType
{
    UNKNOWN    = 0 /**< This should be an error condition. */,
    BASE       = 1 /**< This should be an error condition. */,
    CARTESIAN  = 2 /**< Standard Projection-Less 3-dimensional coordinate */,
    SPHERICAL  = 3 /**< Spherical Coordinate System. */,
    GEOGRAPHIC = 4 /**< Spherical coordinate */,
    GEOCENTRIC = 5 /**< Earth-Centric */,
    ECEF       = 6 /**< Earth-Centered, Earth-Fixed */,

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
