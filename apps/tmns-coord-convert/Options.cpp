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

namespace tmns {

/****************************************/
/*      Print Usage Instructions        */
/****************************************/
void Options::usage() const
{
    std::stringstream sout;
    sout << "usage: " << app_path.filename().native() << " <input-args> <output-args>" << std::endl;

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

} // End of tmns namespace
