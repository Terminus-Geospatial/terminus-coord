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
 * @file    TransverseMercator.hpp
 * @author  Marvin Smith
 * @date    01/09/2025
 */

// Terminus Libraries
#include <terminus/coord/types/Cartesian.hpp>
#include <terminus/math/vector.hpp>

namespace tmns::coord {

/**
 * @class TransverseMercator
 */
class TransverseMercator : public Cartesian {

    public:

        /**
         * Get the coordinate type
         */
        inline CoordinateType coordinate_type() const override {
            return CoordinateType::TRANS_MERC;
        }

}; // End of TransverseMercator class

} // End of tmns::coord namespace