#include <iostream>
#include <vector>
using namespace std;
double lagrangeInterpolation(const vector<double>& x, const vector<double>& y, double x_interp) {
    int n = x.size();
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (x_interp - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

int main() {
    int n;
    double x_interp;
    cout << "Enter the number of data points: ";
    cin >> n;
    vector<double> x(n), y(n);
    cout << "Enter the x values: ";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    cout << "Enter the y values: ";
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }
    cout << "Enter the value of x to interpolate: ";
    cin >> x_interp;
    double result = lagrangeInterpolation(x, y, x_interp);
    cout << "\nThe interpolated value at x = " << x_interp << " is: " << result << endl;
    return 0;
}

