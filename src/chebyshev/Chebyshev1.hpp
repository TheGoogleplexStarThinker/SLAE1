//
// Created by MSI on 05.03.2022.
//

#ifndef MY_PROJECT_CHEBYSHEV1_HPP
#define MY_PROJECT_CHEBYSHEV1_HPP


#include <vector>
#include <cmath>
#include <ctgmath>

template<typename T>
unsigned long long int C(int n, int k){
    unsigned long long int res = 1;
    for(int i = k + 1; i <= n; ++i){
        res *= i;
    }
    for(int i = 1; i <= n-k; ++i){
        res /= i;
    }
    return res;
}

template<typename T, size_t powOf2>
class ChebyshevRoots{
//public:

//    ChebyshevRoots();

    size_t PolyOrder = std::pow(2, powOf2);
    std::vector<T> roots(PolyOrder);

    for(size_t i = 1; i <= PolyOrder; ++i){
        roots[i-1] = (section.first+section.second) / 2 +
                     (section.second - section.first) / 2 *
                     static_cast<T>(cos(static_cast<double >(2 * i - 1) * M_PI_2 / PolyOrder ));
    }

    std::vector<int> idx = {0, 1};
    std::vector<int> next_idx;
    int currOrder;
//    for(int i = 1; i < powOf2)
//    {
//
//    }
}; // ChebyshevRoots

#endif //MY_PROJECT_CHEBYSHEV1_HPP
