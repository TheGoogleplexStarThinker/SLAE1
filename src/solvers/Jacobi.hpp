//
// Created by petrov on 19.02.2022.
//

#ifndef SLAE_JACOBI_HPP
#define SLAE_JACOBI_HPP

#include "../sparse/CSR.hpp"
#include "../utility/Norm.hpp"
#include "../utility/overloads.hpp"

template<typename T>
std::vector<T> Jacobi(const CSR<T> &A, const std::vector<T> &b, const std::vector<T> &initialState, const T &tolerance) {
    std::vector<T> r = A * initialState - b;
    std::vector<T> currentState = initialState;
    std::vector<T> tempState;
    T sum;
    while (norm(r, NormType::ThirdNorm) > tolerance) {
        for (int i = 0; i < A.sizeH(); ++i) {
            sum = static_cast<T>(0);
            int skip = A.rows[i];
            int count = A.rows[i + 1] - skip;
            for (int k = skip; k < skip + count; ++k) {
                if (A.cols[k] != i) {
                    sum += A.values[k] * tempState[A.cols[k]];
                }
            }
            tempState[i] = (b[i] - sum) / A(i, i);
        }
        currentState = tempState;
//        Jacobi to Gauss - Seidel
//        del line 24(28), in line 22(25)  tempState -> currentState

        r = A * currentState - b;
    }

    return currentState;
}


#endif//SLAE_JACOBI_HPP
