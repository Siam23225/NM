#include <bits/stdc++.h>

using namespace std;
double f(double x) {
    return x * x * x - x - 1;
}

double f_prime(double x) {
    return 3 * x * x - 1;
}
void newtonRaphson(double x0, double tol, int max_iter) {
    double x = x0;
    double h;

    cout << fixed << setprecision(6);

    for (int i = 0; i < max_iter; i++) {
        double fx = f(x);
        double fpx = f_prime(x);
        cout << "Iteration " << i + 1 << ": x = " << x << ", f(x) = " << fx << endl;
        if (fabs(fpx) < 1e-10) {
            cout << "Derivative near zero. Stopping the method to avoid division by zero." << endl;
            return;
        }
        h = fx / fpx;
        x = x - h;
        if (fabs(h) < tol) {
            cout << "Root found at x = " << x << " after " << i + 1 << " iterations." << endl;
            return;
        }
    }

    cout << "Maximum iterations reached. Approximate root at x = " << x << " with f(x) = " << f(x) << endl;
}

int main() {
    double x0, tol;
    int max_iter;
    cout << "Enter the initial guess (x0): ";
    cin >> x0;
    cout << "Enter the tolerance: ";
    cin >> tol;
    cout << "Enter the maximum number of iterations: ";
    cin >> max_iter;
    newtonRaphson(x0, tol, max_iter);

    return 0;
}

