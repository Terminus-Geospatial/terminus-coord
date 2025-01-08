#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    January 9, 2025
#
#    Purpose:  Build terminus-coordinate applications

add_executable( tmns-coord-convert 
                main.cpp
                Options.cpp
                Options.hpp )

target_link_libraries( tmns-coord-convert
                       Boost::headers
                       Boost::log
                       terminus_core::terminus_core
                       terminus_log::terminus_log
                       terminus_outcome::terminus_outcome
                       ${PROJECT_NAME} )

