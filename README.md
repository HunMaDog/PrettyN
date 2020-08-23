# PrettyN
Pretty Names

A simple solution to get human readable type names.

```cpp

    #include "detail/prettyn/type_name.hpp"

    #include <iostream>

    constexpr int forty_and_two{42};

    class Answer {
    public:
        constexpr int answer() const noexcept
        {
            return forty_and_two;
        }
    };

    int main()
    {
        using marklar::detail::prettyn::type_name;

        Answer answare;

        auto answare_is = answare.answer();
        std::cout << "Answare type is: " << type_name<decltype(answare_is)>() << '\n';
    
        return 0;
    }

```
