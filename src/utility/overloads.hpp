//
// Created by petrov on 12.02.2022.
//

#ifndef SLAE_OVERLOADS_HPP
#define SLAE_OVERLOADS_HPP

#include <iosfwd>
#include <vector>

/***
 * Умножение числа на вектор
 * @tparam T Тип числа
 * @param k Число
 * @param b Вектор
 * @return Результат умножения
 */
template<typename T>
std::vector<T> operator*(const T &k, const std::vector<T> &b) {
    std::vector<T> res(b.size());

    for (int i = 0; i < b.size(); ++i) {
        res[i] = k * b[i];
    }

    return res;
}

/***
 * Умножение вектора на число
 * @tparam T Тип числа
 * @param b Вектор
 * @param k Число
 * @return Результат умножения
 */
template<typename T>
std::vector<T> operator*(const std::vector<T> &b, const T &k) {
    std::vector<T> res(b.size());

    for (int i = 0; i < b.size(); ++i) {
        res[i] = b[i] * k;
    }

    return res;
}

/***
 * Скалярное перемножение векторов
 * @tparam T Тип элементов векторов
 * @param a Первый вектор
 * @param b Второй вектор
 * @return Результат скалярного перемножения
 */
template<typename T>
T operator*(const std::vector<T> &a, const std::vector<T> &b) {
    T res = 0;

    for (int i = 0; i < b.size(); ++i) {
        res += a[i] * b[i];
    }

    return res;
}

/***
 * Вычитание двух векторов
 * @tparam T Тип элементов векторов
 * @param a Первый вектор
 * @param b Второй вектор
 * @return Результат вычитания векторов
 */
template<typename T>
std::vector<T> operator-(const std::vector<T> &a, const std::vector<T> &b) {
    std::vector<T> res(a.size());

    for (int i = 0; i < b.size(); ++i) {
        res[i] = a[i] - b[i];
    }

    return res;
}

/***
 * Сложение двух векторов
 * @tparam T Тип элементов векторов
 * @param a Первый вектор
 * @param b Второй вектор
 * @return Результат сложения векторов
 */
template<typename T>
std::vector<T> operator+(const std::vector<T> &a, const std::vector<T> &b) {
    std::vector<T> res(a.size());

    for (int i = 0; i < b.size(); ++i) {
        res[i] = a[i] + b[i];
    }

    return res;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &b) {
    for (int i = 0; i < b.size(); ++i) {
        os << b[i] << " ";
    }

    return os;
}

#endif//SLAE_OVERLOADS_HPP
