//
// Created by MSI on 23.04.2022.
//

#ifndef MY_PROJECT_KRYLOV_HPP
#define MY_PROJECT_KRYLOV_HPP

#include <../src/sparse/CSR.hpp>
#include <../src/dense/densematrix.hpp>
#include <../src/utility/overloads.hpp>
#include <../src/utility/Norm.hpp>
#include <vector>

template<typename T>
void KrylovSubSpace(const CSR<T> &A, std::vector<std::vector<T>> &Basis, DenseMatrix<T> &H, size_t N, const T &tolerance) {
    std::vector<T> v = Basis.back();

    T h;

    v = A * Basis[N];
    for (size_t i = 0; i < N + 1; ++i) {
        h = Basis[i] * v;
        v = v - h * Basis[i];

        if (T_abs(h) > tolerance) {
            H(i, N) = h;
        }
    }
    v = 1.0 / h * v;
    Basis.push_back(v);
}

#endif //MY_PROJECT_KRYLOV_HPP
