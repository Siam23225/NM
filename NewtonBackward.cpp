#include <bits/stdc++.h>
using namespace std;
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

void backwardDifferenceTable(vector<vector<double>>& diff_table, const vector<double>& y, int n) {
    for (int i = 0; i < n; i++)
        diff_table[i][0] = y[i];
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            diff_table[i][j] = diff_table[i][j - 1] - diff_table[i - 1][j - 1];
        }
    }
}
double newtonBackwardInterpolation(const vector<double>& x, const vector<vector<double>>& diff_table, int n, double x_interp) {
    double h = x[1] - x[0];
    double u = (x_interp - x[n - 1]) / h;
    double result = diff_table[n - 1][0];
    for (int i = 1; i < n; i++) {
        double u_term = u;
        for (int j = 1; j < i; j++) {
            u_term *= (u + j);
        }
        result += (u_term * diff_table[n - 1][i]) / factorial(i);
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
    vector<vector<double>> diff_table(n, vector<double>(n, 0.0));
    backwardDifferenceTable(diff_table, y, n);
    cout << "\nBackward Difference Table:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << setw(10) << diff_table[i][j] << "\t";
        }
        cout << endl;
    }
    double result = newtonBackwardInterpolation(x, diff_table, n, x_interp);
    cout << "\nThe interpolated value at x = " << x_interp << " is: " << result << endl;

    return 0;
}

