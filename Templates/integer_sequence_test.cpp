#include <iostream>
std::index_sequence;

#include "integer_sequence_.hpp"

int main()
{
    // using seq_1 = demo::integer_sequence<size_t, 0, 1, 2>;
    // using seq_2 = demo::integer_sequence<size_t, 0, 1, 2>;
    // using seq = demo::detail::append_integer_sequence<seq_1, seq_2>::type;
    // std::cout << 123 << std::endl;
    // std::cout << typeid(seq{}).name() << std::endl;

    // demo::index_sequence<1,2,3,4> test;

    using seq = demo_recite::make_integer_sequence<size_t, 12>;
    // static_assert(std::is_same_v<seq,
    //                              demo::integer_sequence<size_t, 0, 1>> == true);
    std::cout << typeid(seq{}).name() << std::endl;

    return 0;
};