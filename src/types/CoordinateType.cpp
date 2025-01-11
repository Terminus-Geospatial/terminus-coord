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
 * @file    CoordinateType.cpp
 * @author  Marvin Smith
 * @date    01/08/2025
 */
#include <terminus/coord/types/CoordinateType.hpp>

// C++ Standard Libraries
#include <algorithm>


namespace tmns::coord {

/********************************************/
/*      Convert CoordinateType to String    */
/********************************************/
std::string to_string( CoordinateType tp )
{
    switch( tp )
    {
        case CoordinateType::BASE:
            return "BASE";
        case CoordinateType::CARTESIAN:
            return "CARTESIAN";
        case CoordinateType::ECEF:
            return "ECEF";
        case CoordinateType::GEOGRAPHIC:
            return "GEOGRAPHIC";
        case CoordinateType::SPHERICAL:
            return "SPHERICAL";
        case CoordinateType::TRANS_MERC:
            return "TRANS_MERC";
        case CoordinateType::UTM:
            return "UTM";
        default:
            return "UNKNOWN";
    }
    return "UNKNOWN";
}

/*********************************************/
/*      Convert String to CoordinateType     */
/*********************************************/
CoordinateType to_coordinate_type( const std::string& tp )
{
    auto tp_lower = tp;
    std::transform( tp_lower.begin(), tp_lower.end(), tp_lower.begin(), ::tolower );
    
    // Base
    if( tp_lower == "base" ){
        return CoordinateType::BASE;
    }

    // Cartesian
    if( tp_lower == "cartesian" ){
        return CoordinateType::CARTESIAN;
    }

    // ECEF/Geocentric
    if( tp_lower == "ecef" ){
        return CoordinateType::ECEF;
    }
    if( tp_lower == "geocentric" ){
        return CoordinateType::GEOCENTRIC;
    }

    // Geographic
    if( tp_lower == "geographic" ){
        return CoordinateType::GEOGRAPHIC;
    }

    // Spherical
    if( tp_lower == "spherical" ){
        return CoordinateType::SPHERICAL;
    }

    // Transverse Mercator
    if( tp_lower == "trans_merc" ){
        return CoordinateType::TRANS_MERC;
    }

    // UTM
    if( tp_lower == "utm" ){
        return CoordinateType::UTM;
    }

    // Otherwise
    return CoordinateType::UNKNOWN;
}

} // End of tmns::coord namespace
