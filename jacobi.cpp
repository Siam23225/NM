#include <bits/stdc++.h>
using namespace std;

void jacobi(double A[][10], double b[], double x[], int n, double tol, int maxIt) {
    double x_new[10]; // Temporary array to store new values of x in each iteration
    cout << fixed << setprecision(5);
    cout << "Iteration\tsolution\n";

    for (int it = 0; it <= maxIt; it++) {
        bool converged = true;
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (i != j)
                    sum += A[i][j] * x[j];
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }

        cout << it << "\t\t";
        for (int i = 0; i < n; i++) {
            cout << x_new[i] << " ";
            if (fabs(x_new[i] - x[i]) > tol) {
                converged = false;
            }
            x[i] = x_new[i]; // Update x for the next iteration
        }
        cout << endl;

        if (converged) {
            cout << "Converged after " << it << " iterations.\n";
            return;
        }
    }

    cout << "Reached max iterations. Approximate solution: ";
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;
}

int main() {
    int n, it;
    double A[10][10], b[10], x[10] = {0}, tol;
    cout << "Enter the number of variables: ";
    cin >> n;
    cout << "Enter the coefficient matrix A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    }
    cout << "Enter the constant matrix b:\n";
    for (int i = 0; i < n; i++)
        cin >> b[i];
    cout << "Enter the tolerance: ";
    cin >> tol;
    cout << "Enter the maximum number of iterations: ";
    cin >> it;

    jacobi(A, b, x, n, tol, it);
}
