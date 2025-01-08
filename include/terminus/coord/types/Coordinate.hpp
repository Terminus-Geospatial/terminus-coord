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
 * @file    Coordinate_Base.hpp
 * @author  Marvin Smith
 * @date    01/08/2025
 */
#pragma once

// C++ Libraries
#include <map>
#include <string>

// Terminus Libraries
#include <terminus/coord/types/CoordinateType.hpp>

namespace tmns::coord {

/**
 * @class Coordinate
 */
class Coordinate
{
    public:

        Coordinate() = default;

        /**
         * Construct a new Coordinate.
         * Do not use this unless you know what you are doing
         */
        Coordinate( CoordinateType type );

        virtual ~Coordinate() = default;

        /**
         * Get the coordinate type
         */
        virtual CoordinateType coordinate_type() const;

        /**
         * Print coordinate contents in log-friendly string
         */
        virtual std::string to_log_string( size_t offset = 0 ) const;

        /**
         * Return coordinate contents in KVP
         */
        virtual std::map<std::string,std::string> as_map() const;

    private:

        /// Coordinate Type stored internally
        CoordinateType m_type { CoordinateType::BASE };

};// End of Coordinate_Base class

} // End of tmns::coord namespace
