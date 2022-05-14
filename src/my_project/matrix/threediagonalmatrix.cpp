//
// Created by MSI on 05.02.2022.
//

#include "threediagonalmatrix.hpp"

namespace Slae::Matrix {
    three_diag_matrix::three_diag_matrix(unsigned int size) : data_(size) {}

    three_diag_matrix three_diag_matrix::Zero(unsigned int size) {
        three_diag_matrix result(size);
//        for (auto &string:std::array<double, 3>&result.data_) {
//            string = {0., 0., 0.};
//        }
        return result;
    }

    double &three_diag_matrix::operator()(unsigned int i, unsigned int j) {
        if (i >= data_.size()) {
//            std::string
        }
        return data_[i][j];
    }
}
