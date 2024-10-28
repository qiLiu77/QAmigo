#ifndef COMBINE_H
#define COMBINE_H

#include <cstdint>
#include <type_traits>

template <size_t N>
struct SelectIntType;

template <>
struct SelectIntType<2> { using type = int16_t; };

template <>
struct SelectIntType<3> { using type = int32_t; };

template <>
struct SelectIntType<4> { using type = int32_t; };

template <>
struct SelectIntType<5> { using type = int64_t; };

template <>
struct SelectIntType<6> { using type = int64_t; };

template <>
struct SelectIntType<7> { using type = int64_t; };

template <>
struct SelectIntType<8> { using type = int64_t; };

template <std::size_t N, bool MakeUnsigned = true, typename T>
constexpr auto combineToInt(const T& arr, std::size_t start)
{
    static_assert(N >= 2 && N <= 8, "Varargs count must be between 2 and 8");
    using SignedType = typename SelectIntType<N>::type;
    using ReturnType = std::conditional_t<MakeUnsigned, std::make_unsigned_t<SignedType>, SignedType>;
    ReturnType result = 0;

    for (size_t i = 0; i < N; i++)
    {
        result |= static_cast<ReturnType>(static_cast<uint8_t>(arr[start + i])) << (i * 8);
    }
    return result;
}

#endif
