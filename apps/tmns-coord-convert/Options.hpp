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
 * @file    Options.hpp
 * @author  Marvin Smith
 * @date    01/08/2025
 */
#pragma once

// C++ Standard Libraries
#include <filesystem>
#include <map>
#include <string>

// Terminus Libraries
#include <terminus/coord/utilities/KeyType.hpp>

namespace tmns {

/**
 * @class Options
 */
class Options
{
    public:

        // Application Path
        std::filesystem::path app_path;

        // List of input parameters
        std::map<coord::KeyType,std::string> input_parameters;

        /**
         * Print usage instructions
         */
        void usage() const;

        /**
         * Parse Command-Line Options
         */
        static Options parse_command_line( int argc, char* argv[], char* envp[] );

};// End of Options class

} // End of tmns namespace
