#include <DES/rng-utils.hpp>
#include <DES/des.hpp>
#include <functional>
#include <iostream>

auto eval_point(const des::Point& px, std::function<double(des::Point)> func) -> double {
	return func(px);
}

auto eval_pop(const des::Population& pop, std::function<double(des::Point)> func) -> std::vector<double> {
	std::vector<double> fitness;

	for (int i = 0; i < pop.cols(); ++i) 
		fitness.push_back(func(pop.col(i)));

	return fitness;	
}

auto sphere(des::Point px) -> double {
	return px.squaredNorm();
}

