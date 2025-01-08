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
 * @file    string_utilities.hpp
 * @author  Marvin Smith
 * @date    01/09/2025
 */
#pragma once

// C++ Standard Libraries
#include <map>
#include <optional>
#include <string>


/**
 * Find a value from a KVP map using key
 * @param key Key to search in the map with.
 * @param data KVP map to search in
 * 
 * @returns optional string.
 */
template <typename Key_Type,
          typename Value_Type>
std::optional<Value_Type> find_in_map( const Key_Type&                      key,
                                       const std::map<Key_Type,Value_Type>& data )
{
    // Iterate through KVP map
    for( const auto& pr : data )
    {
        if( pr.first == key ){
            return pr.second;
        }
    }
    return {};
}