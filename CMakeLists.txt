#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    January 9, 2025
#
#    Purpose:  Build terminus-coordinate API

#  Set CMake Version
cmake_minimum_required( VERSION 3.22 FATAL_ERROR )

#  Configure Conan Search Paths
include( "${CMAKE_BINARY_DIR}/conan_toolchain.cmake" )
set( CMAKE_FIND_PACKAGE_PREFER_CONFIG TRUE )

# Set the Project-Name
project( ${CONAN_PKG_NAME}
         VERSION      ${CONAN_PKG_VERSION}
         HOMEPAGE_URL ${CONAN_PKG_URL}
         DESCRIPTION  ${CONAN_PKG_DESCRIPTION}
         LANGUAGES    CXX )

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

#  Set C++ 20 Support
set( CMAKE_CXX_STANDARD 23 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

#  Give Vscode a fighting chance
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#  Setup libdl for debug GCC builds
if( CMAKE_BUILD_TYPE STREQUAL "debug" OR CMAKE_BUILD_TYPE STREQUAL "Debug" )
    if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
        set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -rdynamic -ldl" )
    endif()
endif()

# Bring in CMake helpers for TERMINUS projects
include( terminus_cmake )

#  Setup Threading (pthreads for linux)
find_package(Threads REQUIRED)

# Find Boost
add_definitions( -DBOOST_ALL_DYN_LINK )
find_package( Boost REQUIRED )
include_directories( ${Boost_INCLUDE_DIRS} )

#  Bring in Terminus Libraries
find_package( terminus_core    REQUIRED )
message( "terminus_core_FOUND: ${terminus_core_FOUND}" )
find_package( terminus_log     REQUIRED )
find_package( terminus_outcome REQUIRED )
find_package( terminus_math    REQUIRED )

#-----------------------------------------#
#-            Setup Filesystem           -#
#-----------------------------------------#

include_directories( include )

add_subdirectory( apps )

add_subdirectory( cookbook )

#------------------------------------------------------#
#-          Construct the Coordinate Library          -#
#----------------------------------------------------#
add_library( ${PROJECT_NAME} SHARED
    include/terminus/coord/types/Cartesian.hpp
    include/terminus/coord/types/Coordinate.hpp
    include/terminus/coord/types/CoordinateType.hpp
    include/terminus/coord/types/Datum.hpp
    include/terminus/coord/types/DatumType.hpp
    include/terminus/coord/types/Geographic.hpp
    include/terminus/coord/types/Spherical.hpp
    include/terminus/coord/types/TransverseMercator.hpp
    include/terminus/coord/types/UTM.hpp
    include/terminus/coord/utilities/Builder.hpp
    include/terminus/coord/utilities/Builder_Utilities.hpp
    include/terminus/coord/utilities/EPSG_Utilities.hpp
    include/terminus/coord/utilities/KeyType.hpp
    src/types/Cartesian.cpp
    src/types/Coordinate.cpp
    src/types/CoordinateType.cpp
    src/types/Datum.cpp
    src/types/DatumType.cpp
    src/types/Geographic.cpp
    src/types/Spherical.cpp
    src/types/TransverseMercator.cpp
    src/types/UTM.cpp
    src/utilities/Builder.cpp
    src/utilities/Builder_Utilities.cpp
    src/utilities/EPSG_Utilities.cpp
    src/utilities/KeyType.cpp
    src/utilities/string_utilities.hpp
)

#  Link in dependencies
target_link_libraries( ${PROJECT_NAME} PUBLIC
    Boost::headers
    Boost::log
    Boost::log_setup
    Boost::stacktrace
    Boost::system
    terminus_core::terminus_core
    terminus_log::terminus_log
    terminus_math::terminus_math
    terminus_outcome::terminus_outcome
    Threads::Threads
)

install( TARGETS ${PROJECT_NAME} )

terminus_lib_configure( ${PROJECT_NAME} )

#  Enable code coverage
if( TERMINUS_COORD_ENABLE_COVERAGE )
     terminus_coverage_enable()
endif()

#--------------------------------#
#-      Build Unit Tests        -#
#--------------------------------#
if( TERMINUS_COORD_ENABLE_TESTS )
    enable_testing()
    add_subdirectory( test/unit )
endif()

install( DIRECTORY include/terminus DESTINATION include)