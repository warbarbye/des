#include <DES/des.hpp>
#include <DES/rng-utils.hpp>
#include <iostream>
#include <cmath>
#include <cassert>
#include <random>

#define assertm(exp, msg) assert(((void)msg, exp))

namespace des {

	auto check_boundries(int N, const Point& lower, const Point& upper) -> void {
		assertm(lower.size() == N, "Vector with lower boundries has invalid dimension");
		assertm(upper.size() == N, "Vector with upper boundries has invalid dimension");
		int invalid_cnt = 0;
		for (int i = 0; i < lower.size(); ++i)  
			for (int j = 0; j < upper.size(); ++j)
				invalid_cnt += upper[j] < lower[i] ? 1 : 0;
		assertm(invalid_cnt == 0, "In upper boundries vector exist values smaller than in lower boundries vector.");
	}

	auto compute_weights(int mu) -> std::vector<double> {
		std::vector<double> w(mu);
		return w;
	}

	auto compute_mueff(std::vector<double> weights) -> double {
		return 1;
	}

	des::des(int N, double Ft, int lambda, int mu,  std::vector<double> weights, double cc, double cp, double mu_eff,
			double path_ratio, int path_length, double hist_size, double tol, double budget) : 
		N{N}, Ft{Ft}, lambda{lambda}, mu{mu}, weights{weights}, cc{cc}, cp{cp}, mu_eff{mu_eff}, 
		path_ratio{path_ratio}, path_length{path_length}, hist_size{hist_size}, tol{tol},
		budget{budget}, t{0}, counteval{0} {}

	des::des(int N, double Ft, int path_length, double tol) :
		N{N}, Ft{Ft}, path_length{path_length}, tol{tol}, t{0}, counteval{0} {
			if (N < 0 || Ft < 0 || path_length < 0 || tol < 0)
				throw(std::invalid_argument("N, Ft, path length and tol must be positive."));
			budget = 10000*N;
			lambda = 4*N;
			mu = floor(lambda/2);
			cc = mu/(mu+2);
			cp = 1/sqrt(N);
			maxiter = floor(budget/(lambda+1));
			path_ratio = sqrt(path_length);
			hist_size = ceil(6+ceil(3*sqrt(N)));
		}

	auto des::view_params() -> void {	
		std::cout << "N = " << this->N << std::endl; 
		std::cout << "Ft = " << this->Ft << std::endl; 
		std::cout << "lambda = " << this->lambda << std::endl; 
		std::cout << "mu = " << this->mu << std::endl; 
		std::cout << "cc = " << this->cc << std::endl; 
		std::cout << "cp = " << this->cp << std::endl; 
		std::cout << "hist_size = " << this->hist_size << std::endl; 
		std::cout << "path_ratio = " << this->path_ratio << std::endl; 
		std::cout << "path_length = " << this->path_length << std::endl; 
		std::cout << "maxiter = " << this->maxiter << std::endl; 
		std::cout << "tol = " << this->tol << std::endl; 
		std::cout << "budget = " << this->budget << std::endl; 
	}
	auto des::view_name() -> void {
		std::cout << "Differential Evolution Strategy" << std::endl;
	}
	auto des::get_name() -> std::string {
		return "Differential Evolution Strategy";
	}

	auto des::run(Point init, std::function<double(Point)>, Point lower, Point upper) -> Log {

		check_boundries(N, lower, upper);

		std::vector<double> log_Ft(N);
		std::vector<Point> log_mean(N);
		std::vector<Point> log_bestVal(N);
		std::vector<double> log_value(N);


		while (counteval < budget) {
		}
		return this->log;
	}
}
