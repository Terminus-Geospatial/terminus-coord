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
 * @file    Coordinate.hpp
 * @author  Marvin Smith
 * @date    01/09/2025
 */
#include <terminus/coord/types/Coordinate.hpp>

// C++ Standard Libraries
#include <sstream>

namespace tmns::coord {

/*************************************/
/*      Parameterized Constructor    */
/*************************************/
Coordinate::Coordinate( CoordinateType type )
    : m_type { type }
{
}

/********************************/
/*      Get Coordinate Type     */
/********************************/
CoordinateType  Coordinate::coordinate_type() const {
    return m_type;
}

/*****************************************/
/*      Print to Log-Friendly String     */
/*****************************************/
std::string Coordinate::to_log_string( size_t offset = 0 ) const 
{
    std::string gap( offset, ' ' );
    std::stringstream sout;
    sout << gap << "Coordinate:" << std::endl;
    sout << gap << "  - type: " << to_string( m_type );

    return sout.str();
}

} // End of tmns::coord namespace
