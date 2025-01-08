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
 * @file    KeyType.hpp
 * @author  Marvin Smith
 * @date    01/09/2025
 */
#pragma once

// C++ Standard Libraries
#include <string>

namespace tmns::coord {

/**
 * Key-Type
 */
enum class KeyType {
    UNKNOWN         = 0,
    COORDINATE_TYPE = 1,
    EPSG_CODE       = 2,
}; // End of KeyType enumeration


/**
 * Convert KeyType to String
 */
std::string to_string( KeyType tp );

/**
 * Convert String to KeyType
 */
KeyType to_keytype( const std::string& tp );

} // End of tmns::coord namespace