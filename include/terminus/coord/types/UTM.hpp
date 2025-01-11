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
 * @file    UTM.hpp
 * @author  Marvin Smith
 * @date    01/09/2025
 */
#pragma once

// Terminus Libraries
#include <terminus/coord/types/Datum.hpp>
#include <terminus/coord/types/TransverseMercator.hpp>
#include <terminus/math/vector.hpp>

namespace tmns::coord {

/**
 * @class UTM
 */
class UTM : public TransverseMercator {

    public:

        /**
         * Get the coordinate type
         */
        inline CoordinateType coordinate_type() const override {
            return CoordinateType::UTM;
        }

        /**
         * @brief Return the Datum
         */
        inline Datum datum() const {
            return m_datum;
        }

        /**
         * @brief Create UTM coordinate
         * 
         * @param grid_zone
         * @param easting_meters
         * @param northing_meters
         * @param elevation_meters
         * @param datum
         */
        static UTM create( int    grid_zone,
                           double easting_meters,
                           double northing_meters,
                           double elevation_meters,
                           Datum  datum = Datum::from_default( DatumType::WGS_84 ) );

    private:

        /**
         * Constructor
         */
        UTM( int    grid_zone,
             double easting_meters,
             double northing_meters,
             double elevation_meters,
             Datum  datum = Datum::from_default( DatumType::WGS_84 ) );

        // Underlying array
        math::Vector3d m_data { math::ToVector3<double>( 0, 0, 0 ) };

        // Grid Zone
        int m_grid_zone { 0 };

        // Datum
        Datum m_datum { Datum::from_default( DatumType::WGS_84 ) };

}; // End of UTM class

} // End of tmns::coord namespace