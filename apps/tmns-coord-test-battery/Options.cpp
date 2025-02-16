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
#include <sstream>
#include <string>

// Toml++
#include <toml++/toml.h>

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

    bool gen_config = false;

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

        // Check config path
        else if( arg == "-c" || arg == "--config" ){
            options.m_config_path = args.front();
            args.pop_front();
        }

        // Generate config
        else if( arg == "-g" || arg == "--gen-config" ){
            gen_config = true;
        }

        // Otherwise, error
        else {
            tmns::log::error( "Unsupported argument: ", arg );
            options.usage();
            std::exit(1);
        }

    }

    // Make sure user specified config
    if( !options.m_config_path ){
        tmns::log::error( "No config path specified." );
        options.usage();
        std::exit(1);
    }

    // Check if use specified to generate config
    if( gen_config ){
        write_toml( *options.m_config_path );
        std::exit(0);
    }

    // Parse config
    auto res = options.parse_toml( *options.m_config_path );
    if( res.has_error() ){
        tmns::log::error( "Unable to parse config file. ", res.error().message() );
        std::exit(1);
    }


    return options;
}

/**********************************************/
/*            Get the CSV Pathname            */
/**********************************************/
std::optional<std::filesystem::path> Options::get_csv_path( CSV_Type tp ) const
{
    if( m_csv_paths.find( tp ) == m_csv_paths.end() ){
        return {};
    }
    return { m_csv_paths.find( tp )->second };
}

/****************************************************/
/*          Parse the TOML Configuration File       */
/****************************************************/
Result<void> Options::parse_toml( std::filesystem::path toml_path )
{
    // Parse the file
    std::ifstream fin( toml_path );
    if( !fin.good() ){
        return tmns::outcome::fail( core::error::ErrorCode::FILE_IO_ERROR,
                                    "Unable to open file." );
    }

    // Pass to TOML API
    auto data = toml::parse( fin );

    // Fetch the various blocks
    const std::map<CSV_Type,std::string> keys { { CSV_Type::GEOGRAPHIC_TO_GEOGRAPHIC, "proj_geographic_to_geographic" },
                                                { CSV_Type::GEOGRAPHIC_TO_UPS,        "proj_geographic_to_ups" },
                                                { CSV_Type::GEOGRAPHIC_TO_UTM,        "proj_geographic_to_utm" },
                                                { CSV_Type::UPS_TO_GEOGRAPHIC,        "proj_ups_to_geographic" },
                                                { CSV_Type::UTM_TO_GEOGRAPHIC,        "proj_utm_to_geographic" },
                                                { CSV_Type::UTM_TO_UTM,               "proj_utm_to_utm" } };

    // Iterate over the list of keys
    for( const auto& pr : keys )
    {
        // Parse the block
        auto vals = data[pr.second];

    }

    return tmns::outcome::ok();
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
    fout << "#    Date:    " << date_to_string().value() << std::endl;
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
