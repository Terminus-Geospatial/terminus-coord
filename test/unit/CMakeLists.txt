#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    1/9/2025

#  Configure GoogleTest
find_package( GTest REQUIRED )
include( GoogleTest )

include_directories( ${CMAKE_SOURCE_DIR}/include )

set( TEST ${PROJECT_NAME}_test )
add_executable( ${TEST}
    main.cpp
    utilities/TEST_Builder_Utilities.cpp
    utilities/TEST_Builder.cpp
    utilities/TEST_EPSG_Utilities.cpp
)

target_link_libraries( ${TEST} PRIVATE
    GTest::gtest
    ${PROJECT_NAME}
)

gtest_discover_tests( ${TEST} PROPERTIES TIMEOUT 600 )
