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
 * @file    Geographic.hpp
 * @author  Marvin Smith
 * @date    01/09/2025
 */

// Terminus Libraries
#include <terminus/coord/types/Datum.hpp>
#include <terminus/coord/types/Spherical.hpp>
#include <terminus/math/vector.hpp>

namespace tmns::coord {

/**
 * @class Geographic
 */
class Geographic : public Spherical {

    public:

        /**
         * Get the coordinate type
         */
        inline CoordinateType coordinate_type() const override {
            return CoordinateType::GEOGRAPHIC;
        }

        /**
         * @brief Return the Datum
         */
        inline Datum datum() const {
            return m_datum;
        }

        /**
         * @brief Create Geographic coordinate
         * 
         * @param lon_degrees
         * @param lat_degrees
         * @param elev_meters
         */
        static Geographic create( double lon_degrees,
                                  double lat_degrees,
                                  double elev_meters,
                                  Datum  datum = Datum::from_default( DatumType::WGS_84 ) );

    private:

        /**
         * Constructor
         */
        Geographic( double lon_degrees,
                    double lat_degrees,
                    double elev_meters,
                    Datum  datum = Datum::from_default( DatumType::WGS_84 ) );

        // Underlying array
        math::Vector3d m_data { math::ToVector3<double>( 0, 0, 0 ) };

        // Datum
        Datum m_datum { Datum::from_default( DatumType::WGS_84 ) };

}; // End of Geographic class

} // End of tmns::coord namespace
