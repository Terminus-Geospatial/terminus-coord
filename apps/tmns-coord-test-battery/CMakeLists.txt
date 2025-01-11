#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    January 10, 2025
#
#    Purpose:  Build terminus-coordinate coordinate test battery

add_executable( tmns-coord-test-battery 
                main.cpp
                Options.cpp
                Options.hpp
                Utilities.cpp
                Utilities.hpp
                proj/Geographic.cpp
                proj/Geographic.hpp
                proj/UTM.cpp
                proj/UTM.hpp )

target_link_libraries( tmns-coord-test-battery
                       Boost::headers
                       Boost::log
                       terminus_core::terminus_core
                       terminus_log::terminus_log
                       terminus_outcome::terminus_outcome
                       ${PROJECT_NAME} )

