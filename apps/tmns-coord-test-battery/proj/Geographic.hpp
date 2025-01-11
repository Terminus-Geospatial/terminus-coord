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
 * @file    Geographic.hpp
 * @author  Marvin Smith
 * @date    01/12/2025
 */
#pragma once

// C++ Standard Libraries
#include <string>

// Project Libraries
#include "../Options.hpp"

namespace tmns::proj {

/**
 * Run the Geographic to Geographic Battery
 */
std::string run_geographic_to_geographic_battery( std::filesystem::path csv_path );

} // End of tmns::proj namespace