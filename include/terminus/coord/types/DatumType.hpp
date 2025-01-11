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
 * @file    DatumType.hpp
 * @author  Marvin Smith
 * @date    01/09/2025
 */
#pragma once

// C++ Standard Libraries
#include <string>

namespace tmns::coord {

enum class DatumType {
    NAD_27 /**< North American Datum, 1927 */,
    NAD_83 /**< North American Datum, 1983 */,
    WGS_72 /**< World Geodetic System, 1972 */,
    WGS_84 /**< World Geodetic System, 1986 */,
}; // End of DatumType class

/**
 * Convert DatumType to string
 */
std::string to_string( DatumType tp );

/**
 * Convert string to DatumType
 */
DatumType to_datumtype( const std::string& tp );

} // End of tmns::coord namespace
