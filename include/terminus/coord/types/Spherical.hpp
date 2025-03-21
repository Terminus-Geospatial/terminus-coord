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
 * @file    Spherical.hpp
 * @author  Marvin Smith
 * @date    01/08/2025
 */
#pragma once

// Terminus C++ Libraries
#include <terminus/coord/types/Coordinate.hpp>

namespace tmns::coord {

/**
 * @class Spherical
 * 
 * Defines spherical coordinates with 3 components
 */
class Spherical : public Coordinate
{
    public:

        /**
         * Get the coordinate type
         */
        inline CoordinateType coordinate_type() const override {
            return CoordinateType::SPHERICAL;
        }
        

    private:

};// End of Spherical class

} // End of tmns::coord namespace
