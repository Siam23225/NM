#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x * x - x - 1;
}

void regulaFalsi(double a, double b, double tol, int max_iter) {
    double c = a;


    if (f(a) * f(b) >= 0) {
        cout << "Incorrect initial guesses: f(a) and f(b) should have opposite signs." << endl;
        return;
    }

    cout << fixed << setprecision(6);

    for (int i = 0; i < max_iter; i++) {

        c = (a * f(b) - b * f(a)) / (f(b) - f(a));


        cout << "Iteration " << i + 1 << ": a = " << a << ", b = " << b << ", c = " << c << ", f(c) = " << f(c) << endl;
        if (fabs(f(c)) <= tol) {
            cout << "Root found at x = " << c << " after " << i + 1 << " iterations." << endl;
            return;
        }
        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    cout << "Maximum iterations reached. Approximate root at x = " << c << " with f(c) = " << f(c) << endl;
}

int main() {
    double a, b, tol;
    int max_iter;
    cout << "Enter the initial guesses (a and b): ";
    cin >> a >> b;
    cout << "Enter the tolerance: ";
    cin >> tol;
    cout << "Enter the maximum number of iterations: ";
    cin >> max_iter;
    regulaFalsi(a, b, tol, max_iter);

    return 0;
}

