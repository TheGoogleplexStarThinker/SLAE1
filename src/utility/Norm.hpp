//
// Created by petrov on 19.02.2022.
//

#ifndef SLAE_NORM_HPP
#define SLAE_NORM_HPP

#include <vector>
#include <cmath>

enum class NormType {
    FirstNorm = 1,
    SecondNorm = 2,
    ThirdNorm = 3
};

template<typename T>
const T &norm(const std::vector<T> &vector, NormType normType) {
    T norm = static_cast<T>(0);
    if (normType == NormType::FirstNorm) {
//        T abs;
        norm = std::max(abs(std::max(vector)), abs(std::min(vector)));
//        abs = std::abs(elm);
//        if (abs > norm) norm = abs;
    }

    if (normType == NormType::SecondNorm) {
        for (const auto &elm: vector) {
            norm += abs(elm);
        }
    }

    if (normType == NormType::ThirdNorm) {
        for (const auto &elm: vector) {
            norm += elm * elm;
        }

        norm = sqrt(norm);
    }

    return norm;
}

template<typename T>
T T_abs(const T &a) {
    if (a < static_cast<T>(0)) {
        return -a;
    } else {
        return a;
    }
}

#endif//SLAE_NORM_HPP
