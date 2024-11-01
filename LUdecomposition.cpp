#include <bits/stdc++.h>
using namespace std;

void LU(double A[][10], double L[][10], double U[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i)
                L[j][i] = 0;
            else {
                L[j][i] = A[j][i];
                for (int k = 0; k < i; k++)
                    L[j][i] -= L[j][k] * U[k][i];
            }
        }
        for (int j = i; j < n; j++) {
            if (j == i)
                U[i][j] = 1;
            else {
                U[i][j] = A[i][j];
                for (int k = 0; k < i; k++)
                    U[i][j] -= L[i][k] * U[k][j];
                U[i][j] /= L[i][i];
            }
        }
    }
}

void forward(double L[][10], double b[], double y[], int n) {
    for (int i = 0; i < n; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++)
            y[i] -= L[i][j] * y[j];
        y[i] /= L[i][i];
    }
}

void back(double U[][10], double x[], double y[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++)
            x[i] -= U[i][j] * x[j];
        x[i] /= U[i][i];
    }
}

int main() {
    int n;
    double A[10][10], L[10][10] = {0}, U[10][10] = {0}, b[10], y[10], x[10];
    cout << "Enter the number of variables: ";
    cin >> n;

    cout << "Enter the coefficient matrix A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter the constant vector b:\n";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    LU(A, L, U, n);
    forward(L, b, y, n);
    back(U, x, y, n);

    cout << "Solution:\n";
    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " << x[i] << endl;

}
