//
// Created by petrov on 19.02.2022.
//

#ifndef SLAE_GAUSSSEIDEL_HPP
#define SLAE_GAUSSSEIDEL_HPP

#include "../sparse/CSR.hpp"
#include "../utility/Norm.hpp"
#include "../utility/overloads.hpp"
#include <vector>

template<typename T>
std::vector<T> GaussSeidel(const CSR<T> &A, const std::vector<T> &b, const std::vector<T> &initialState, const T &tolerance) {
    std::vector<T> r = A * initialState - b;
    std::vector<T> currentState = initialState;
    T sum;
    while (norm(r, NormType::ThirdNorm) > tolerance) {
        for (int i = 0; i < A.sizeH(); ++i) {
            sum = static_cast<T>(0);
            int skip = A.rows[i];
            int count = A.rows[i + 1] - skip;
            for (int k = skip; k < skip + count; ++k) {
                if (A.cols[k] != i) {
                    sum += A.values[k] * currentState[i];
                }
            }
            currentState[i] = (b[i] - sum) / A(i, i);
        }

        r = A * currentState - b;
    }

    return currentState;
}

#endif//SLAE_GAUSSSEIDEL_HPP
