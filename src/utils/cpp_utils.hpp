/**
 * @copyright (c) Copyright 2020 . All Rights Reserved.
 * @license
 * @file  : cpp_utils.hpp
 * @author: Jona 
 * @email : wuzhenyu@secsmart.net
 * @date  : 2020-10-22
 * @brief : cpp utils
*/

namespace utils {

// convenient functions to avoid lengthy dynamic_cast() != nullptr checks in many places
template <typename T1, typename T2>
inline bool is(T2 *obj) { // for pointer types
  return dynamic_cast<typename std::add_const<T1>::type>(obj) != nullptr;
}
  
} /* end cpp_utils */
