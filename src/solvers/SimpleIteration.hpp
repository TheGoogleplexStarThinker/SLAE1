//
// Created by petrov on 19.02.2022.
//

#ifndef SLAE_SIMPLEITERATION_HPP
#define SLAE_SIMPLEITERATION_HPP

#include "iostream"
#include "vector"
#include "../sparse/CSR.hpp"
#include "../utility/overloads.hpp"
#include "../utility/Norm.hpp"

#define tolerance static_cast<T>(1e-6)

template<typename T>
std::vector<T> SimpleIteration(const CSR<T> &A, const std::vector<T> &b, const T &tao) {
    // начальное приближение
    std::vector<T> x(b.size(), 0);

    // невязка
    std::vector<T> r = A * x - b;

    // кол-во итераций
    int i = 0;
    // сам метод
    while (norm(r, NormType::ThirdNorm) > tolerance){
        x = x - tao * r;
        r = A * x - b;
        ++i;
    }

    // вывод i
//    std::cout << "Метод простой итерации: " << i << std::endl;

    return x;
}


#endif//SLAE_SIMPLEITERATION_HPP
