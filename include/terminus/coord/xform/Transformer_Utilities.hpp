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
 * @file    Transformer.hpp
 * @author  Marvin Smith
 * @date    01/10/2025
 */
#pragma once

// Terminus Libraries
#include <terminus/coord/utilities/KeyType.hpp>

// C++ Standard Libraries
#include <tuple>

namespace tmns::coord {

using XFORM_PARAM = std::tuple<KeyType,std::string>;

template <typename ArgType>
XFORM_PARAM Param( KeyType kt, const ArgType& arg )
{
    return std::make_tuple( kt, std::to_string( arg ) );
}

template <>
XFORM_PARAM Param( KeyType kt, const std::string& arg )
{
    return std::make_tuple( kt, arg );
}


} // End of tmns::coord namespace