/* 
 *
 * @file des.hpp
 * @author Eryk Warchulski
*/


#ifndef DES_HPP
#define DES_HPP

#include <functional>
#include <string>
#include <vector>
#include <any>
#include <map>
#include "Eigen/Dense"

namespace des {
	using Log = std::map<std::string, std::any>;
	using Point = Eigen::VectorXd;
	using Population = Eigen::MatrixXd;

	auto check_boundries(int N, const Point& lower, const Point& upper) -> void;

	class des {
	public:
		des(int N, double Ft, int lambda, int mu,  std::vector<double> weights, double cc, double cp, double mu_eff,
			double path_ratio, int path_length, double hist_size, double tol, double budget);
		des(int N, double Ft, int path_length, double tol);
		auto view_params() -> void;
		auto view_name() -> void;
		auto get_name() -> std::string;
		auto run(Point init, std::function<double(Point)>, Point lower, Point upper) -> Log;
	private:
		double Ft;
		double budget;
		std::vector<double> weights;
		double mu_eff;
		double cc;
		double cp;
		double path_ratio;
		double hist_size;
		double tol;
		int path_length;
		int counteval;
		int lambda;
		int maxiter;
		int mu;
		int N;
		int t;
		Log log;
	};
}
#endif
