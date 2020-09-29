#include <DES/rng-utils.hpp>
#include <vector>

template<typename Distro>
auto random_point(int size, double par1, double par2) -> des::Point {
	std::default_random_engine generator;
	Distro dist{par1, par2};
	std::vector<double> random_numbers(size); 
	std::generate(random_numbers.begin(), random_numbers.end(), [&](){
			return dist(generator);
		}
	);
	des::Point random_point(size);
	for (int i = 0; i < random_point.size(); ++i)
		random_point[i] = random_numbers[i];
	return random_point;
}

template<typename Distro>
auto random_population(int nrow, int ncol, double par1, double par2) -> des::Population {
	std::vector<des::Point> points(ncol);
	std::generate(points.begin(), points.end(), [&](){
			return random_point<Distro>(nrow, par1, par2);
		}
	);

	des::Population pop(nrow, ncol);
	for (int i = 0; i < ncol; ++i)
		pop.col(i) = points[i];
	return pop;
}

int main() {
	return 0;
}

