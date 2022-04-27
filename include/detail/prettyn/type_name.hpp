/*
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */
#ifndef MARKLAR_DETAIL_PRETTYN_TYPE_NAME_HPP
#define MARKLAR_DETAIL_PRETTYN_TYPE_NAME_HPP

// Marklar headers
#include "underlying_type_name.hpp"
// External library headers
// C++ standard library headers
#include <string_view>

/*
 * Simple pretty type name getter
 */
namespace marklar::detail::prettyn
{
template<typename Type>
constexpr auto
type_name()
{
    /*
     * PRETTYN_UNDERLYING_NAME_GETTER is defined in "underlying_type_name.hpp" and it is helps to separate the compiler
     * dependent part and stable part. It is hold a compiler dependent define to get function name and size of prefix and suffix.
     */
    std::string_view name{PRETTYN_UNDERLYING_FUNCTION_NAME_GETTER};

    name.remove_prefix(size_of_prefix);
    name.remove_suffix(size_of_suffix);

    return name;
}

} // namespace marklar::detail::prettyn

#endif // MARKLAR_DETAIL_PRETTYN_TYPE_NAME_HPP
