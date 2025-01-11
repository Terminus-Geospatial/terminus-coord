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
 * @file    main.cpp
 * @author  Marvin Smith
 * @date    01/08/2025
 */

// Terminus C++ Libraries
#include <terminus/coord/utilities/Builder.hpp>

// Project Libraries
#include "proj/UTM.hpp"
#include "Options.hpp"


int main( int argc, char* argv[], char* envp[] ) {

    auto options = tmns::Options::parse_command_line( argc, argv, envp );

    std::stringstream sout;

    // Run Proj Tests
    sout << tmns::proj::run_geographic_to_geographic_battery( options.get_csv_path( tmns::CSV_Type::GEOGRAPHIC_TO_GEOGRAPHIC ) ) << std::endl;
    sout << tmns::proj::run_geographic_to_utm_battery( options.get_csv_path( tmns::CSV_Type::GEOGRAPHIC_TO_UTM ) ) << std::endl;
    sout << tmns::proj::run_utm_to_geographic_battery( options.get_csv_path( tmns::CSV_Type::UTM_TO_GEOGRAPHIC ) ) << std::endl;
    sout << tmns::proj::run_utm_to_utm_battery( options.get_csv_path( tmns::CSV_Type::UTM_TO_GEOGRAPHIC ) ) << std::endl;

    return 0;
}