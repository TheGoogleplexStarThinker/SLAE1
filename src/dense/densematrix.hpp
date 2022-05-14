//
// Created by petrov on 12.02.2022.
//

#ifndef SLAE_DENSEMATRIX_HPP
#define SLAE_DENSEMATRIX_HPP

#include <vector>
#include <set>
#include "../utility/Triplet.hpp"
#include "ostream"

// Dense matrix
template<typename T>
class DenseMatrix {

    using elm_t = T;
    using idx_t = std::size_t;

private:

    std::vector<T> matrix;
    idx_t H, W;

public:

    DenseMatrix(const idx_t &h, const idx_t &w) : W(w), H(h) {
        matrix.resize(W * H);
    }

    DenseMatrix(const idx_t &h, const idx_t &w, const std::set<Triplet<T>> &in) : W(w), H(h) {
        matrix.resize(W * H);
        for (auto i: in) {
            matrix[i.i * W + i.j] = i.value;
        }
    }

    elm_t &operator()(const idx_t &i, const idx_t &j) {
        return matrix[i * W + j];
    }

    const elm_t &operator()(const idx_t &i, const idx_t &j) const {
        return matrix[i * W + j];
    }

    [[nodiscard]] const idx_t &sizeH() const {
        return H;
    }

    [[nodiscard]] const idx_t &sizeW() const {
        return W;
    }

    void swap(const idx_t &first, const idx_t &second) {
        for (idx_t j = 0; j < W; ++j) {
            std::swap(matrix[first * W + j], matrix[second * W + j]);
        }
    }

    void deleteLastRow() {
        --H;
        matrix.erase(matrix.end() - W, matrix.end());
    }

}; // Dense matrix

// Matrix and vector multiplication
template<typename T>
std::vector<T> operator*(const DenseMatrix<T> &A, const std::vector<T> &b) {
    std::vector<T> res(A.sizeH());
    T sum;
    for (std::size_t i = 0; i < A.sizeH(); ++i) {
        sum = 0;
        for (std::size_t j = 0; j < A.sizeW(); ++j) {
            sum += A[i, j] * b[j];
        }
        res[i] = sum;
    }
    return res;
} // Matrix and vector multiplication

// Dense matrix display
template<typename T>
std::ostream &operator<<(std::ostream &os, const DenseMatrix<T> &A) {
    for (std::size_t i = 0; i < A.sizeH(); ++i) {
        for (std::size_t j = 0; j < A.sizeW(); ++j) {
            os << A(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
} // Dense matrix display

#endif//SLAE_DENSEMATRIX_HPP
