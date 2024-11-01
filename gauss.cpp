#include <bits/stdc++.h>
using namespace std;

void GS(double A[][10], double b[], double x[], int n, double tol, int it)
{
    cout << fixed << setprecision(5);
    cout << "Iteration\tsolution\n";
    for (int iter = 1; iter <= it; iter++)
    {
        bool converged = true;
        for (int i = 0; i < n; i++)
        {
            double sum = 0.0;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    sum += A[i][j] * x[j];
            }
            double new_x = (b[i] - sum) / A[i][i];
            if (fabs(new_x - x[i]) > tol) // Fix convergence check
                converged = false;
            x[i] = new_x;
        }

        cout << iter << "\t\t";
        for (int i = 0; i < n; i++)
            cout << x[i] << " ";
        cout << endl;

        if (converged)
        {
            cout << "Converged after " << iter << " iterations.\n";
            return;
        }
    }

    cout << "Reached max iterations. Approximate solutions: ";
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;
}

int main()
{
    int n, maxIt;
    double A[10][10], b[10], x[10] = {0}, tol;

    cout << "Enter the number of variables (max 10): ";
    cin >> n;
    if (n > 10) {
        cout << "The number of variables must not exceed 10." << endl;
        return 1; // Exit with error code
    }

    cout << "Enter the coefficient matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter the constant matrix b:\n";
    for (int i = 0; i < n; i++)
        cin >> b[i];

    cout << "Enter the tolerance: ";
    cin >> tol;

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIt;

    GS(A, b, x, n, tol, maxIt);

    return 0;
}
