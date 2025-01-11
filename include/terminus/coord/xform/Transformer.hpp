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
#include <terminus/coord/xform/Transformer_Utilities.hpp>
#include <terminus/core/error/ErrorCategory.hpp>

// C++ Standard Libraries
#include <initializer_list>

namespace tmns::coord {

/**
 * Executes all coordinate conversion calls
 */
class Transformer
{
    public:

        static Result<Transformer> create( CoordinateType                     dest_cs,
                                           std::initializer_list<XFORM_PARAM> args );

    private:


}; // End of Transformer Class


} // End of tmns::coord namespace