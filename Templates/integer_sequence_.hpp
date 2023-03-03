namespace demo_recite
{
    template <typename T, T... Ns>
    struct integer_sequence
    {
    };

    template <size_t... Ns>
    using index_sequence = integer_sequence<size_t, Ns...>;

    namespace detail
    {
        template <bool C, typename T1, typename T2>
        struct conditional_impl;

        template <typename T1, typename T2>
        struct conditional_impl<true, T1, T2>
        {
            using type = T1;
        };

        template <typename T1, typename T2>
        struct conditional_impl<false, T1, T2>
        {
            using type = T2;
        };

        template <typename T>
        struct identity
        {
            using type = T;
        };

        template <bool C, typename T1, typename T2>
        using conditional = conditional_impl<C, T1, T2>::type;

        template <typename T, T N>
        struct make_integer_sequence_impl;

        template <typename T1, typename T2>
        struct append;

        template <typename T, T... Ns, T... Ms>
        struct append<integer_sequence<T, Ns...>, integer_sequence<T, Ms...>>
        {
            using type = integer_sequence<T, Ns..., (Ms + sizeof...(Ns))...>;
        };
        template <typename T, T N>
        struct make_integer_sequence_impl_
        {
            static T const M = N / 2;
            static T const R = N % 2;

            using S1 = typename make_integer_sequence_impl<T, M>::type;
            using S2 = typename append<S1, S1>::type;
            using S3 = typename make_integer_sequence_impl<T, R>::type;
            using S4 = typename append<S2, S3>::type;

            using type = S4;
        };

        template <typename T, T N>
        struct make_integer_sequence_impl : public conditional<
                                                N == 0,
                                                identity<integer_sequence<T>>,
                                                conditional<
                                                    N == 1,
                                                    identity<integer_sequence<T, 0>>,
                                                    make_integer_sequence_impl_<T, N>>>
        {
        };
    };

    template <typename T, T N>
    using make_integer_sequence = detail::make_integer_sequence_impl<T, N>::type;
};
