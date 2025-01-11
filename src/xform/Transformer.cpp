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
 * @file    Transformer.cpp
 * @author  Marvin Smith
 * @date    01/10/2025
 */
#include <terminus/coord/xform/Transformer.hpp>

namespace tmns::coord {

/****************************************/
/*          Construct Transformer       */
/****************************************/
Result<Transformer> Transformer::create( CoordinateType                     dest_cs,
                                         std::initializer_list<XFORM_PARAM> args )
{
    return tmns::outcome::ok<Transformer>( Transformer() );
}

} // End of tmns::coord namespace