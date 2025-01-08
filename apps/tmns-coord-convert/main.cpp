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
#include "Options.hpp"


int main( int argc, char* argv[], char* envp[] ) {

    // Parse Command-Line Options
    auto config = tmns::Options::parse_command_line( argc, argv, envp );

    // Construct input coordinate
    auto input_coord = tmns::coord::Builder::create_from_kvp_map( config.input_parameters );

    // Determine output coordinate

    return 0;
}