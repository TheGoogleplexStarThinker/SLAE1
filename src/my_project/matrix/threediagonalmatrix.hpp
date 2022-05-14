//
// Created by MSI on 05.02.2022.
//

#ifndef MY_PROJECT_THREEDIAGONALMATRIX_HPP
#define MY_PROJECT_THREEDIAGONALMATRIX_HPP



#include <vector>
#include <array>

namespace Slae::Matrix {

    class three_diag_matrix {
        /*** поля класса ***/

        std::vector<std::array<double, 3>> data_;

    public:
        explicit three_diag_matrix(unsigned int size);
        static three_diag_matrix Zero(unsigned int size);

        double &operator()(unsigned int i, unsigned int j);

        [[nodiscard]] const double &operator()(unsigned int i, unsigned int j) const;

    };

} //namespace Slae::Matrix




#endif //MY_PROJECT_THREEDIAGONALMATRIX_HPP
