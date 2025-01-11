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
 * @file    Options.cpp
 * @author  Marvin Smith
 * @date    01/08/2025
 */
#include "Options.hpp"

// C++ Standard Libraries
#include <deque>
#include <string>

// Terminus Libraries
#include <terminus/log.hpp>

// Project Libraries
#include "Utilities.hpp"

namespace tmns {

/****************************************/
/*      Print Usage Instructions        */
/****************************************/
void Options::usage() const
{
    std::stringstream sout;
    sout << "usage: " << app_path.filename().native() << " -c <config-toml>" << std::endl;
    sout << std::endl;
    sout << " -c <config toml> : Path to configuration file in TOML format." << std::endl;
    sout << " -g : Flag to generate configuration file. Will write to -c path." << std::endl;
    sout << std::endl;

    tmns::log::info( sout.str() );
}


/***************************************/
/*      Parse Command-Line Options     */
/***************************************/
Options Options::parse_command_line( int argc, char* argv[], char* envp[] )
{
    Options options;
    options.app_path = std::filesystem::path( argv[0] );

    std::deque<std::string> args;
    for( int i = 1; i < argc; i++ ){
        args.push_back( argv[i] );
    }

    while( !args.empty() )
    {
        // Fetch next argument
        auto arg = args.front();
        args.pop_front();

        // Check argument if help
        if( arg == "--help" || arg == "-h" ){
            options.usage();
            std::exit(0);
        }

    }


    return options;
}

/****************************************************/
/*          Parse the TOML Configuration File       */
/****************************************************/
void parse_toml( std::filesystem::path toml_path )
{
    

}

/********************************/
/*      Write TOML to disk      */
/********************************/
void Options::write_toml( std::filesystem::path toml_path )
{
    std::ofstream fout;
    fout.open( toml_path );

    fout << "#" << std::endl;
    fout << "#    File:    " << toml_path.filename().native() << std::endl;
    fout << "#    Date:    " << date_to_string() << std::endl;
    fout << "#" << std::endl;
    fout << std::endl;

    // Geographic to Geographic
    fout << "[proj_geographic_to_geographic]" << std::endl;
    fout << "enabled = true" << std::endl;
    fout << "path = ./apps/tmns-coord-test-battery/data/proj_geographic_to_geographic.csv" << std::endl;
    fout << std::endl;

    // Proj Geographic to UTM
    fout << "[proj_geographic_to_utm]" << std::endl;
    fout << "enabled = true" << std::endl;
    fout << "path = ./apps/tmns-coord-test-battery/data/proj_geographic_to_utm.csv" << std::endl;
    
    // Proj UTM to Geographic
    fout << "[proj_utm_to_geographic]" << std::endl;
    fout << "enabled = true" << std::endl;
    fout << "path = ./apps/tmns-coord-test-battery/data/proj_utm_to_geographic.csv" << std::endl;
    
    // Proj UTM to UTM
    fout << "[proj_utm_to_utm]" << std::endl;
    fout << "enabled = true" << std::endl;
    fout << "path = ./apps/tmns-coord-test-battery/data/proj_utm_to_utm.csv" << std::endl;


    fout.close();
}

} // End of tmns namespace
