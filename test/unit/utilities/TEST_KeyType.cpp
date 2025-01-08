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
 * @file    TEST_EPSG_Utilities.cpp
 * @author  Marvin Smith
 * @date    01/09/2025
 */
#include <gtest/gtest.h>

// Terminus Libraries
#include <terminus/coord/utilities/KeyType.hpp>

using namespace tmns;

/*************************************/
/*      Convert Key-Type to String   */
/*************************************/
TEST( KeyType, to_string )
{
    ASSERT_EQ( coord::to_string( coord::KeyType::UNKNOWN ),         "UNKNOWN" );
    ASSERT_EQ( coord::to_string( coord::KeyType::COORDINATE_TYPE ), "COORDINATE_TYPE" );
    ASSERT_EQ( coord::to_string( coord::KeyType::EPSG_CODE ),       "EPSG_CODE" );
}

/****************************************/
/*      Convert String to Key-Type      */
/****************************************/
TEST( KeyType, from_string )
{
    ASSERT_EQ( coord::from_string( "coordinate_type" ), coord::KeyType::COORDINATE_TYPE );
    ASSERT_EQ( coord::from_string( "COORDINATE_TYPE" ), coord::KeyType::COORDINATE_TYPE );

    ASSERT_EQ( coord::from_string( "epsg_code" ), coord::KeyType::EPSG_CODE );
    ASSERT_EQ( coord::from_string( "EPSG_CODE" ), coord::KeyType::EPSG_CODE );

    // Failure Cases
    ASSERT_EQ( coord::from_string( "" ),             coord::KeyType::UNKNOWN );
    ASSERT_EQ( coord::from_string( "asdlkjfasdfl" ), coord::KeyType::UNKNOWN );
}
