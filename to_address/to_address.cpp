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

#include <cassert>
#include <memory>
#include <assert.h>
#include <iostream>
#include <type_traits>
#include <functional>

template<class A>
auto allocator_new(A& a)
{
    auto p = a.allocate(1);
    try {
        std::allocator_traits<A>::construct(a, std::to_address(p));
    }
    catch (...) {
        a.deallocate(p, 1);
        throw;
    }
    return p;
}

template<class A>
void allocator_delete(A& a, typename std::allocator_traits<A>::pointer p)
{
    std::allocator_traits<A>::destroy(a, std::to_address(p));
    a.deallocate(p, 1);
}

void test01() {
    std::allocator<int> a;
    auto p = allocator_new(a);
    allocator_delete(a, p);
}

template<class T>
class P1 {
public:
    explicit P1(T* p)
        : p_(p) { }

    T* operator->() const noexcept {
        return p_;
    }

private:
    T* p_;
};

template<class T>
class P2 {
public:
    explicit P2(T* p)
        : p_(p) { }

    P1<T> operator->() const noexcept {
        return p_;
    }

private:
    P1<T> p_;
};

template<class T>
class P3 {
public:
    explicit P3(T* p)
        : p_(p) { }

    T* get() const noexcept {
        return p_;
    }

private:
    T* p_;
};

namespace std {

    template<class T>
    struct pointer_traits<P3<T> > {
        static T* to_address(const P3<T>& p) noexcept {
            return p.get();
        }
    };
} // std

template<class T>
class P4 {
public:
    explicit P4(T* p)
        : p_(p) { }

    T* operator->() const noexcept {
        return nullptr;
    }

    T* get() const noexcept {
        return p_;
    }

private:
    int* p_;
};

namespace std {

    template<class T>
    struct pointer_traits<P4<T> > {
        static T* to_address(const P4<T>& p) noexcept {
            return p.get();
        }
    };

} // std

void test02() {
    int i = 0;
    assert(std::to_address(&i) == &i);
    int* p = &i;
    assert(std::to_address(p) == &i);
    P1<int> p1(&i);
    assert(std::to_address(p1) == &i);
    P2<int> p2(&i);
    assert(std::to_address(p2) == &i);
    P3<int> p3(&i);
    assert(std::to_address(p3) == &i);
    P4<int> p4(&i);
    assert(std::to_address(p4) == &i);
}

void test03() {
    std::cout << std::boolalpha
        << std::is_same_v<std::remove_cvref_t<int>, int> << std::endl
        << std::is_same_v<std::remove_cvref_t<int&>, int> << std::endl
        << std::is_same_v<std::remove_cvref_t<int&&>, int> << std::endl
        << std::is_same_v<std::remove_cvref_t<const int&>, int> << std::endl
        << std::is_same_v<std::remove_cvref_t<const int[2]>, int[2]> << std::endl
        << std::is_same_v<std::remove_cvref_t<const int(&)[2]>, int[2]> << std::endl
        << std::is_same_v<std::remove_cvref_t<int(int)>, int(int)> << std::endl;
}

int minus(int a, int b) {
    return a - b;
}
void test04() {
    auto fifty_minus = std::bind_front(&minus, 50);
    std::cout << fifty_minus(3) << std::endl;
}

int main()
{
    std::cout << "Toaddress tests" << std::endl;
    test01();
    test02();
    test03();
    test04();
    return 0;
}
