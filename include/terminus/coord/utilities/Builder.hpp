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
 * @file    Builder.hpp
 * @author  Marvin Smith
 * @date    01/08/2025
 */
#pragma once

// Terminus Libraries
#include <terminus/coord/types/Coordinate.hpp>
#include <terminus/coord/utilities/KeyType.hpp>
#include <terminus/core/error/ErrorCategory.hpp>


namespace tmns::coord {

/**
 * @class Builder
 */
class Builder
{
    public:

        /**
         * Construct a coordinate from a Key/Value Pair map.  This is helpful for command-line applications
         * and other uses where the information is different depending on configuration data. 
         */
        static Result<Coordinate> create_from_kvp_map( std::map<KeyType,std::string> coord_data );

    private:

};// End of Builder class

} // End of tmns::coord namespace
