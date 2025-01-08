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
 * @file    string_utilities.hpp
 * @author  Marvin Smith
 * @date    01/09/2025
 */
#include <gtest/gtest.h>

// Terminus Libraries
#include <terminus/coord/utilities/EPSG_Utilities.hpp>

using namespace tmns;

/*******************************************************/
/*      Convert from EPSG Code into Coordinate Type    */
/*******************************************************/
TEST( EPSG_Utilities, from_epsg )
{
    ASSERT_EQ( coord::from_epsg( 4326 ).value(), coord::CoordinateType::GEOGRAPHIC );
}
