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

enum class CSV_Type {
    GEOGRAPHIC_TO_GEOGRAPHIC = 1,
    GEOGRAPHIC_TO_UTM        = 2,
    UTM_TO_GEOGRAPHIC        = 3,
    UTM_TO_UTM               = 4,
}; // End of CSV_Type enum

/**
 * @class Options
 */
class Options
{
    public:

        // Application Path
        std::filesystem::path app_path;

        /**
         * Print usage instructions
         */
        void usage() const;

        /**
         * Parse Command-Line Options
         */
        static Options parse_command_line( int argc, char* argv[], char* envp[] );

        /**
         * Get a specific CSV file
         */
        std::optional<std::filesystem::path> get_csv_path( CSV_Type tp ) const;

    private:

        void parse_toml( std::filesystem::path toml_path );

        static void write_toml( std::filesystem::path toml_path );

};// End of Options class

} // End of tmns namespace
