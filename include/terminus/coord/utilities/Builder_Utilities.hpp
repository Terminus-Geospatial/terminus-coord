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
 * @file    Builder_Utilities.hpp
 * @author  Marvin Smith
 * @date    01/08/2025
 */
#pragma once

// Terminus Libraries
#include <terminus/coord/types/CoordinateType.hpp>
#include <terminus/coord/utilities/KeyType.hpp>
#include <terminus/core/error/ErrorCategory.hpp>

namespace tmns::coord::build {

/**
 * Get the coordinate type from a KVP list
 * 
 * Priority list:
 * 1. Coordinate-Name explicitly listed
 * 2. EPSG code
 * 
 */
Result<CoordinateType> find_coordinate_type( const std::map<KeyType,std::string>& kvp );

} // End of tmns::coord::build namespace