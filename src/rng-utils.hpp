#ifndef RNG_UTILS_HPP
#define RNG_UTILS_HPP

#include <random>
#include "des.hpp"

using normal_distro = std::normal_distribution<double>;
using uniform_distro = std::uniform_real_distribution<double>;

template<typename Distro>
auto random_point(int size, double par1, double par2) -> des::Point;

template<typename Distro>
auto random_population(int nrow, int ncol, double par1, double par2) -> des::Population;


#endif
