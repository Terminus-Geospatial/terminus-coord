#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    January 9, 2025
#
#    Purpose:  Build terminus-coordinate cookbook applications

add_executable( convert-geog-to-utm 
                convert-geog-to-utm.cpp )

target_link_libraries( convert-geog-to-utm 
                       Boost::headers
                       Boost::log
                       terminus_core::terminus_core
                       terminus_log::terminus_log
                       terminus_outcome::terminus_outcome
                       ${PROJECT_NAME} )