/**
MIT License

Copyright (c) 2020 Lucile Madoulaud

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

**/

#include <bit>
#include <bitset>
#include <concepts>
#include <cstdint>
#include <initializer_list>
#include <iostream>
#include <numeric>

namespace std 
{
    template <class To, class From>
    typename std::enable_if<(sizeof(To) == sizeof(From)) &&
        std::is_trivially_copyable<From>::value&&
        std::is_trivial<To>::value,To>::type
        bit_cast(const From& src) noexcept
    {
        To dst;
        std::memcpy(&dst, &src, sizeof(To));
        return dst;
    }

    template <std::unsigned_integral T>
    requires !std::same_as<T, bool> && !std::same_as<T, char>
    constexpr bool has_single_bit(T x) noexcept
    {
        return x != 0 && (x & (x - 1)) == 0;
    }
}

// ---
// Example from: 
// https://en.cppreference.com/w/cpp/numeric/bit_cast

constexpr double f64v = 19880124.0;
auto u64v = std::bit_cast<std::uint64_t>(f64v);

constexpr std::uint64_t u64v2 = 0x3fe9000000000000ull;
auto f64v2 = std::bit_cast<double>(u64v2);

void test01()
{
    std::cout
        << std::fixed << f64v << "f64.to_bits() == 0x"
        << std::hex << u64v << "u64" << std::endl;

    std::cout
        << "f64::from_bits(0x" << std::hex << u64v2 << "u64) == "
        << std::fixed << f64v2 << "f64" << std::endl;
}

// --
// Example from:
// https://en.cppreference.com/w/cpp/numeric/has_single_bit

void test02() {
    using bin = std::bitset<8>;
    std::cout << std::boolalpha;
    for (auto i = 0u; i < 10u; ++i) 
    {
        std::cout << "has_single_bit(" << bin(i) << ") = " << std::has_single_bit(i) << std::endl;
    }
}

// --
// Example from
// https://en.cppreference.com/w/cpp/types/endian

void test03() {
    if (std::endian::little == std::endian::native)
    {
        std::cout << "std::endian::little" << std::endl;
    }
    else if (std::endian::big == std::endian::native)
    {
        std::cout << "std::endian::big" << std::endl;
    }
    else
    {
        std::cout << "std::endian::other" << std::endl;
    }
}

// --
// Example from
// https://en.cppreference.com/w/cpp/numeric/midpoint

void test04() {
    std::uint32_t a = std::numeric_limits<std::uint32_t>::max();
    std::uint32_t b = std::numeric_limits<std::uint32_t>::max() - 2;

    std::cout 
        << "a: " << a << std::endl
        << "b: " << b << std::endl
        << "Incorrect (overflow and wrapping): " << (a + b) / 2 << std::endl
        << "Correct: " << std::midpoint(a, b) << std::endl;
}

// --
// Example from
// https://en.cppreference.com/w/cpp/numeric/lerp

void test05() {
    std::cout << "$a + t(b - a)$ = " << std::lerp(1., 5., 2) << std::endl;
}

int main() {
    std::cout << "Bit tests" << std::endl;
    test01();
    test02();
    test03();
    test04();
    test05();
    return 0;
}