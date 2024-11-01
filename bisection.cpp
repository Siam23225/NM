#include <bits/stdc++.h>
using namespace std;
double f(double x) {
    return x * x * x - x - 2;
}

double bisection(double a, double b, double tol, int max_iter) {
    double c;

    for (int i = 0; i < max_iter; i++) {
        c = (a + b) / 2;
        if (fabs(f(c)) < tol) {
            return c;
        }

        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return c;
}

int main() {
    double a, b, tol;
    int max_iter;
    cout << "Enter interval [a, b]: ";
    cin >> a >> b;
    cout << "Enter tolerance: ";
    cin >> tol;
    cout << "Enter max iterations: ";
    cin >> max_iter;


    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval. f(a) and f(b) must have opposite signs." << endl;
    } else {

        double root = bisection(a, b, tol, max_iter);
        cout << "Approximate root: " << root << endl;
    }

    return 0;
}

