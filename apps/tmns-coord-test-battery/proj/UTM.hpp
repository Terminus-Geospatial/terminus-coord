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
 * @file    UTM.hpp
 * @author  Marvin Smith
 * @date    01/08/2025
 */
#pragma once

// C++ Standard Libraries
#include <filesystem>
#include <string>

namespace tmns::proj {


/**
 * Run the LLa to UTM Battery
 */
std::string run_geographic_to_utm_battery( std::filesystem::path csv_path );

/**
 * Run the UTM to LLA Battery
 */
std::string run_utm_to_geographic_battery( std::filesystem::path csv_path );

/**
 * Run the UTM to UTM Battery
 */
std::string run_utm_to_utm_battery( std::filesystem::path csv_path );

} // End of tmns::proj namespace