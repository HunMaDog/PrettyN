/*
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */
#ifndef MARKLAR_DETAIL_PRETTYN_UNDERLYING_TYPE_NAME_HPP
#define MARKLAR_DETAIL_PRETTYN_UNDERLYING_TYPE_NAME_HPP

// Marklar headers
// External library headers
// C++ standard library headers
#include <string_view>
#include <type_traits>

namespace marklar::detail::prettyn
{
/*
 * Compiler dependent solutions
 */

#if defined(__clang__)
template<typename Type>
constexpr std::string_view
clang_pretty_type_name()
{
    std::string_view name{__PRETTY_FUNCTION__};

    constexpr auto size_of_prefix{std::string_view{"std::string_view marklar::detail::prettyn::clang_pretty_type_name() [Type = "}.length()};
    constexpr auto size_of_postfix{std::string_view{"]"}.length()};

    name.remove_prefix(size_of_prefix);
    name.remove_suffix(size_of_postfix);

    return name;
}

#    define PRETTYN_TYPE_NAME_UNDERLYING_FUNCTION(TYPE) clang_pretty_type_name<TYPE>();

#elif defined(__GNUC__)
template<typename Type>
constexpr std::string_view
gcc_pretty_type_name()
{
    std::string_view name{__PRETTY_FUNCTION__};

    constexpr auto size_of_prefix{std::string_view{"constexpr std::string_view marklar::detail::prettyn::gcc_pretty_type_name() [with Type = "}.length()};
    constexpr auto size_of_postfix{std::string_view{"; std::string_view = std::basic_string_view<char>]"}.length()};

    name.remove_prefix(size_of_prefix);
    name.remove_suffix(size_of_postfix);

    return name;
}

#    define PRETTYN_TYPE_NAME_UNDERLYING_FUNCTION(TYPE) gcc_pretty_type_name<TYPE>();

#elif defined(_MSC_VER)
template<typename Type>
constexpr std::string_view
msvc_pretty_type_name()
{
    std::string_view name{__FUNCSIG__};

    constexpr auto size_of_prefix{
        std::string_view{"class std::basic_string_view<char,struct std::char_traits<char> > __cdecl marklar::detail::prettyn::msvc_pretty_type_name<"}.length()};
    constexpr auto size_of_postfix{std::string_view{">(void)"}.length()};

    name.remove_prefix(size_of_prefix);
    name.remove_suffix(size_of_postfix);

    return name;
}

#    define PRETTYN_TYPE_NAME_UNDERLYING_FUNCTION(TYPE) msvc_pretty_type_name<TYPE>();

#endif

} // namespace marklar::detail::prettyn

#endif // MARKLAR_DETAIL_PRETTYN_UNDERLYING_TYPE_NAME_HPP
