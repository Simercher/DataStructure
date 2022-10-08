// #include <bits/stdc++.h>
# include <iostream>
# include <cstring>

using namespace std;

#define MAX_TERM 100

typedef struct
{
    int rows;
    int cols;
    int value;
} Matrix;

void printMatrix(Matrix M[])
{
    cout << endl;
    int n = 0;
    for (int i = 0; i < MAX_TERM; i++) {
        if (M[i].value != 0) n++;
    }
    M[0].value = n - 1;
    cout << n - 1 << endl;
    for (int i = 0; i <= M[0].value + 1; i++)
    {
        // cout << i << " ";
        if (M[i].value != 0)
        {
            cout << M[i].rows << " " << M[i].cols << " " << M[i].value;
        }
        cout << endl;
    }
    // cout << endl;
}

void fastTranspose(Matrix M[], Matrix T[])
{
    int nonZeroRow[M[0].cols], startPos[M[0].cols];
    memset(nonZeroRow, 0, M[0].cols * sizeof(int));
    memset(startPos, 0, M[0].cols * sizeof(int));
    T[0].rows = M[0].rows;
    T[0].cols = M[0].cols;
    T[0].value = M[0].value;
    // cout << endl;
    for (int i = 1; i <= M[0].value; i++)
    {
        // cout << M[i].cols << " " << nonZeroRow[M[i].cols] << endl;
        nonZeroRow[M[i].cols]++;
        // cout << M[i].cols << " " << nonZeroRow[M[i].cols] << endl;
    }
    // cout << endl;

    startPos[0] = 1;

    for (int i = 1; i < M[0].cols; i++)
    {
        // cout << startPos[i - 1] <<" " << nonZeroRow[i - 1] << endl;
        startPos[i] = startPos[i - 1] + nonZeroRow[i - 1];
    }
    // for (int i = 1; i <= M[0].value; i++)
    // {
    //     cout << M[i].cols << " "<< startPos[M[i].cols] << endl;
    // }

    for (int i = 1; i <= M[0].value; i++)
    {
        int j = startPos[M[i].cols]++;
        // cout << j << " " << M[i].cols << endl;
        T[j].rows = M[i].cols;
        T[j].cols = M[i].rows;
        T[j].value = M[i].value;
    }
    // prin tMatrix(T);
}

void multiply(Matrix A[], Matrix BT[])
{
    // cout << endl;
    int max = 1;
    Matrix X[MAX_TERM] = {0};
    // memset(X, 0, MAX_TERM * sizeof(Matrix));
    X[0].rows = A[0].rows;
    X[0].cols = BT[0].cols;
    for (int i = 1; i <= A[0].value; i++)
    {
        for (int j = 1; j <= BT[0].value; j++)
        {
            if (A[i].cols == BT[j].cols)
            {
                int multi = A[i].value * BT[j].value;
                // cout << i << " " << j << " " << A[i].cols << " " << A[i].rows << BT[j].cols << " " << multi << endl;
                X[j].rows = A[i].rows;
                X[j].cols = BT[j].rows;
                X[j].value += multi;
                // if (j > max) max = j;
                // cout << j << " " << X[j].rows << " " << X[j].cols << " " << multi << endl;
                // count++;
            }
        }
    }
    X[0].value = max;
    printMatrix(X);
}

void inputMatrix(Matrix M[])
{
    for (int i = 1; i <= M[0].value; i++)
    {
        cin >> M[i].rows >> M[i].cols >> M[i].value;
    }
}

int main(int argc, char **argv)
{
    int aRows, aCols, aValue, bRows, bCols, bValue;

    cin >> aRows >> aCols >> aValue;
    Matrix matrixA[aValue + 1];
    matrixA[0].rows = aRows;
    matrixA[0].cols = aCols;
    matrixA[0].value = aValue;

    inputMatrix(matrixA);

    // printMatrix(matrixA);

    cin >> bRows >> bCols >> bValue;
    Matrix matrixB[bValue + 1];
    matrixB[0].rows = bRows;
    matrixB[0].cols = bCols;
    matrixB[0].value = bValue;
    inputMatrix(matrixB);
    // printMatrix(matrixB);

    Matrix matrixBT[bValue + 1];
    fastTranspose(matrixB, matrixBT);
    // printMatrix(matrixT, aValue + 1);
    multiply(matrixA, matrixBT);

    return 0;
}