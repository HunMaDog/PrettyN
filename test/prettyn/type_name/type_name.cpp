#include "detail/prettyn/type_name.hpp"

// Marklar headers
// External library headers
#include "../catch.hpp"
// C++ standard library headers
#include <algorithm>
#include <string>

/*
 * Need remove spaces from type name to perform uniform checking
 */
std::string
remove_space(std::string_view data)
{
    std::string string{data};

    string.erase(std::remove(string.begin(), string.end(), ' '), string.end());

    return string;
}

/*
 * Built in types
 */
template<typename Type>
Type
value();

template<typename Type>
Type &
lref();

template<typename Type>
Type const &
const_lref();

template<typename Type>
Type &&
rref();

static const std::string type_int_value{"int"};
static const std::string type_int_lref{"int&"};
static const std::string type_int_const_lref{"constint&"};
static const std::string type_int_rref{"int&&"};

int type_int{42};

TEST_CASE("marklar::detail::prettyn::type_name should be handle value type")
{
    using marklar::detail::prettyn::type_name;

    REQUIRE(type_int_value == remove_space(type_name<decltype(type_int)>()));
    REQUIRE(type_int_value == remove_space(type_name<decltype(value<int>())>()));
}

TEST_CASE("marklar::detail::prettyn::type_name should be handle left reference type")
{
    using marklar::detail::prettyn::type_name;

    REQUIRE(type_int_lref == remove_space(type_name<decltype(static_cast<int &>(type_int))>()));
    REQUIRE(type_int_lref == remove_space(type_name<decltype(lref<int>())>()));
}

TEST_CASE("marklar::detail::prettyn::type_name should be handle const left reference type")
{
    using marklar::detail::prettyn::type_name;

    REQUIRE(type_int_const_lref == remove_space(type_name<decltype(static_cast<const int &>(type_int))>()));
    REQUIRE(type_int_const_lref == remove_space(type_name<decltype(const_lref<int>())>()));
}

TEST_CASE("marklar::detail::prettyn::type_name should be handle right reference type")
{
    using marklar::detail::prettyn::type_name;

    REQUIRE(type_int_rref == remove_space(type_name<decltype(static_cast<int &&>(type_int))>()));
    REQUIRE(type_int_rref == remove_space(type_name<decltype(rref<int>())>()));
}
