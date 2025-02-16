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
 * @file    Utilities.cpp
 * @author  Marvin Smith
 * @date    01/12/2025
 */
#include "Utilities.hpp"

// C++ Libraries
#include <chrono>
#include <format>

namespace tmns {

/************************************************/
/*      Convert Time to Formatted String        */
/************************************************/
Result<std::string> date_to_string()
{
    // Get the current time 
    auto now = std::chrono::system_clock::now(); 
    
    // Convert to time_t to get calendar time 
    auto t = std::chrono::system_clock::to_time_t(now); 
    
    // Convert to tm struct for local time 
    std::tm local_time = *std::localtime(&t); 
    
    // Use std::format to format the current date 
    std::string formatted_date = std::format( "{:%Y-%m-%d}", local_time ); 
    return outcome::ok<std::string>( formatted_date );
}

} // End of tmns namespace
