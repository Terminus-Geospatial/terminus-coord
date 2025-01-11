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
 * @file    Utilities.hpp
 * @author  Marvin Smith
 * @date    01/10/2025
 */
#pragma once

// C++ Libraries
#include <string>

// Terminus Libraries
#include <terminus/core/error/ErrorCategory.hpp>

namespace tmns {

/**
 * Convert date and time to string
 */
Result<std::string> date_to_string();


} // End of tmns namespace
