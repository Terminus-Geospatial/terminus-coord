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
 * @file    KeyType.cpp
 * @author  Marvin Smith
 * @date    01/09/2025
 */
#include <terminus/coord/utilities/KeyType.hpp>

// C++ Standard Libraries
#include <algorithm>

namespace tmns::coord {

/**************************************/
/*      Convert KeyType to String     */
/**************************************/
std::string to_string( KeyType kp ){

    switch( kp )
    {
        case KeyType::COORDINATE_TYPE:
            return "COORDINATE_TYPE";
        case KeyType::EPSG_CODE:
            return "EPSG_CODE";
        default:
            return "UNKNOWN";
    }
    return "UNKNOWN";
}

/********************************/
/*      Convert from String     */
/********************************/
KeyType to_keytype( const std::string& tp )
{
    auto tp_lower = tp;
    std::transform( tp_lower.begin(), tp_lower.end(), tp_lower.begin(), ::tolower );

    if( tp_lower == "coordinate_type" ){
        return KeyType::COORDINATE_TYPE;
    }

    if( tp_lower == "epsg_code" ){
        return KeyType::EPSG_CODE;
    }

    return KeyType::UNKNOWN;
}

} // End of tmns::coord namespace
