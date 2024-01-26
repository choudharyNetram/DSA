#include <iostream>
#include <cmath>
#include <functional>

double ellipse(double x, double R, double Q) {
    double Q_rad = Q * M_PI / 180.0;
    double term = 1 - pow(x * cos(Q_rad) / R, 2);
    return (term >= 0) ? R * sqrt(term) : 0.0;
}

double circle(double x, double r) {
    double term = pow(r, 2) - pow(x, 2);
    return (term >= 0) ? r : 0.0;
}

double integrate(std::function<double(double)> func, double a, double b, int num_steps) {
    double step_size = (b - a) / num_steps;
    double result = 0.5 * (func(a) + func(b));

    for (int i = 1; i < num_steps; ++i) {
        double x = a + i * step_size;
        result += func(x);
    }

    return result * step_size;
}

int main() {
    double R, r, Q;
    std::cout << "Enter R, r, and Q (in degrees): ";
    std::cin >> R >> r >> Q;

    double Q_rad = Q * M_PI / 180.0;

    std::function<double(double)> common_area_func = [R, r, Q_rad](double x) {
        return std::min(ellipse(x, R, Q_rad), circle(x, r));
    };

    double common_area = integrate(common_area_func, -R, R, 100000);

    std::cout << "Common Area: " << common_area << std::endl;

    return 0;
}