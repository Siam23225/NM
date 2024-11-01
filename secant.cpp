#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x * x - 4 * x - 9;
}

void secant(double x0, double x1, double tol, int maxIt) {
    double x2;
    cout << fixed << setprecision(5);
    cout << "Iteration\tx0\t\tx1\t\tf(x1)\n";

    for (int it = 1; it <= maxIt; it++) {
        double fx0 = f(x0);
        double fx1 = f(x1);

        if (fabs(fx1) < tol) {
            cout << "Root found: " << x1 << " after " << it << " iterations.\n";
            return;
        }

        cout << it << "\t\t" << x0 << "\t\t" << x1 << "\t\t" << fx1 << "\n";

        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
        x0 = x1;
        x1 = x2;
    }
    cout << "Root found: " << x1 << " after " << maxIt << " iterations.\n";
}

int main() {
    double x0, x1, tol;
    int maxIt;
    cout << "Enter the first and second initial guess: ";
    cin >> x0 >> x1;
    cout << "Enter tolerance: ";
    cin >> tol;
    cout << "Enter the maximum number of iterations: ";
    cin >> maxIt;
    secant(x0, x1, tol, maxIt);
}
