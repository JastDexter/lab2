#include <iostream>
#include <cmath>

using namespace std;

double function(double x) //возвращает значение функции f(x) = x^2-ln(1+1)-3
{
    return x * x - log(1 + x) - 3;
}

double derivative_1(double x) {
    return 2 * x - 1 / (x + 1);
}

double simple_iteration_method(double x0, double lambda, int max_iterations, double eps, bool details_flag) {
    double x = x0;
    int i = 0;
    do {
        x0 = x;
        x = x - lambda * function(x0);
        i++;
        if (details_flag)
            cout << i << ":  x(n+1) = " << x << " \tx(n)  = " << x0 << " \t abs(x(n+1) - x(n) = " << abs(x - x0)
                 << endl;
    } while (abs(x - x0) > eps && i <= max_iterations);
    if (i == max_iterations)
        return NAN;
    else
        return x;
}

int main() {
    double left, right, eps;
    int max_iterations;
    bool details_flag;
    cout << "Input left bound: " << endl;
    cin >> left;
    cout << "Input right bound: " << endl;
    cin >> right;
    cout << "Input maximum iterations: " << endl;
    cin >> max_iterations;
    cout << "Input accuracy: " << endl;
    cin >> eps;
    cout << "Print details?(1 or 0) : " << endl;
    cin >> details_flag;

    if (function(left) * function(right) > 0) {
        cout << "This segment has no roots" << endl;
        return -1;
    }

    if (left > right) {
        double temp = left;
        left = right;
        right = temp;
    }

    double x0 = (right - left) / 2 + left;
    double lambda = 1 / derivative_1(x0);
    cout << simple_iteration_method(x0, lambda, max_iterations, eps, details_flag);

    return 0;
}
