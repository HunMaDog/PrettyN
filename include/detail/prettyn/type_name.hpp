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
     * PRETTYN_TYPE_NAME_UNDERLYING_FUNCTION is defined in "underlying_type_name.hpp" and it is helps to separate the compiler
     * dependent part and stable part. It is hold a template function call with the given type which returns with the pretty type name.
     */
    return PRETTYN_TYPE_NAME_UNDERLYING_FUNCTION(Type);
}

} // namespace marklar::detail::prettyn

#endif // MARKLAR_DETAIL_PRETTYN_TYPE_NAME_HPP
