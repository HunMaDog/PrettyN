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

#if defined(__GNUC__) and !defined(__clang__)

#    define PRETTYN_UNDERLYING_FUNCTION_NAME_GETTER __PRETTY_FUNCTION__

static constexpr auto size_of_prefix{std::string_view{"constexpr auto marklar::detail::prettyn::type_name() [with Type = "}.length()};
static constexpr auto size_of_suffix{std::string_view{"]"}.length()};

#elif defined(__clang__)

#    define PRETTYN_UNDERLYING_FUNCTION_NAME_GETTER __PRETTY_FUNCTION__

static constexpr auto size_of_prefix{std::string_view{"auto marklar::detail::prettyn::type_name() [Type = "}.length()};
static constexpr auto size_of_suffix{std::string_view{"]"}.length()};

#elif defined(__INTEL_LLVM_COMPILER)

#    define PRETTYN_UNDERLYING_FUNCTION_NAME_GETTER __PRETTY_FUNCTION__

static constexpr auto size_of_prefix{std::string_view{"auto marklar::detail::prettyn::type_name() [Type = "}.length()};
static constexpr auto size_of_suffix{std::string_view{"]"}.length()};

#elif defined(_MSC_VER)

#    define PRETTYN_UNDERLYING_FUNCTION_NAME_GETTER __FUNCSIG__

static constexpr auto size_of_prefix{std::string_view{"auto __cdecl marklar::detail::prettyn::type_name<"}.length()};
static constexpr auto size_of_suffix{std::string_view{">(void)"}.length()};

#else

#    warning "Your compiler is not supported. Please modify this file in order to work properly."

#endif

} // namespace marklar::detail::prettyn

#endif // MARKLAR_DETAIL_PRETTYN_UNDERLYING_TYPE_NAME_HPP
