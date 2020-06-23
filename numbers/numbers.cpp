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

#include <numbers>
#include <iostream>

void test01() {
    std::cout << "std::numbers::e: " << std::numbers::e << " " << std::numbers::e_v<double> << std::endl;
    std::cout << "std::numbers::log2e: " << std::numbers::log2e << " " << std::numbers::log2e_v<double> << std::endl;
    std::cout << "std::numbers::log10e: " << std::numbers::log10e << " " << std::numbers::log10e_v<double> << std::endl;
    std::cout << "std::numbers::pi: " << std::numbers::pi << " " << std::numbers::pi_v<double> << std::endl;
    std::cout << "std::numbers::inv_pi: " << std::numbers::inv_pi << " " << std::numbers::inv_pi_v<double> << std::endl;
    std::cout << "std::numbers::inv_sqrtpi: " << std::numbers::inv_sqrtpi << " " << std::numbers::inv_sqrtpi_v<double> << std::endl;
    std::cout << "std::numbers::ln2: " << std::numbers::ln2 << " " << std::numbers::ln2_v<double> << std::endl;
    std::cout << "std::numbers::ln10: " << std::numbers::ln10 << " " << std::numbers::ln10_v<double> << std::endl;
    std::cout << "std::numbers::sqrt2: " << std::numbers::sqrt2 << " " << std::numbers::sqrt2_v<double> << std::endl;
    std::cout << "std::numbers::sqrt3: " << std::numbers::sqrt3 << " " << std::numbers::sqrt3_v<double> << std::endl;
    std::cout << "std::numbers::inv_sqrt3: " << std::numbers::inv_sqrt3 << " " << std::numbers::inv_sqrt3_v<double> << std::endl;
    std::cout << "std::numbers::egamma: " << std::numbers::egamma << " " << std::numbers::egamma_v<double> << std::endl;
    std::cout << "std::numbers::phi: " << std::numbers::phi << " " << std::numbers::phi_v<double> << std::endl;
    std::cout << "std::numbers::e: " << std::numbers::e << " " << std::numbers::e_v<double> << std::endl;
}

int main() {
    std::cout << "Numbers tests" << std::endl;
    test01();
    return 0;
}
