//
// Created by petrov on 19.02.2022.
//

#ifndef MY_PROJECT_ADVGAUSSSEIDEL_HPP
#define MY_PROJECT_ADVGAUSSSEIDEL_HPP
#include "../sparse/CSR.hpp"
#include "../utility/Norm.hpp"
#include "vector"

template<typename T>
std::vector<T> GaussSeidelIteration(const CSR<T> &A, const std::vector<T> &b, const std::vector<T> &initialState, const T &tolerance){
    std::vector<T> prevState = initialState;
    std::vector<T> r = A * initialState - b;
    std::vector<T> currentState = initialState;
    std::vector<T> nextState = initialState;
    T sum;

    while (norm(r, NormType::ThirdNorm) > tolerance){
        for (int i = 0; i < A.sizeH(); ++i) {
            sum = static_cast<T>(0);
            int skip = A.rows[i];
            int count = A.rows[i+1] - skip;
            for (int k = skip; k < skip + count; ++k){
                if (A.cols[k] != i) sum += A.values[k] * currentState[i];
            }
            currentState[i] = (b[i] - sum) / A(i,i);
        }

        r = A * currentState - b;
    }
}

template<typename T>
std::vector<T> FastGaussSeidel(const CSR<T> &A, const std::vector<T> &b, const std::vector<T> &initialState, const T &tolerance, T rho) {
    auto mu0 = static_cast<T>(1.);
    auto mu1 = static_cast<T>(1./rho);
    auto mu2 = static_cast<T>(2. * mu1 / rho - mu0);
    std::vector<T> prevState = initialState;
    std::vector<T> r = A * initialState - b;
    std::vector<T> currentState = initialState;
    std::vector<T> nextState = initialState;
    while (norm(r, NormType::ThirdNorm) > tolerance){
        nextState = static_cast<T>(2. * mu1 / rho * GaussSeidelIteration(A, b, currentState) - mu0 / mu2 * prevState);
        currentState = b;
        prevState = currentState;
        currentState = nextState;
        mu2 = static_cast<T>(2. * mu1 / rho - mu0);
    }
    return nextState;
}

#endif //MY_PROJECT_ADVGAUSSSEIDEL_HPP
