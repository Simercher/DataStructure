// #include <bits/stdc++.h>
#include <iostream>
// #include <Algorithm>

using namespace std;

#define MAX_TERM 100

typedef struct
{
    int rows = 0;
    int cols = 0;
    int value = 0;
} Matrix;

void printMatrix(Matrix M[])
{
    // cout << endl;
    for (int i = 0; i <= M[0].value; i++)
    {
        // cout << i << " ";
        if (M[0].value == 0)
            break;
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
    int nonZeroRow[M[0].cols] = {0}, startPos[M[0].cols] = {0};
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

    for (int i = 1; i < M[0].value; i++)
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
    // printf("rr");
    // printMatrix(T);
}

void multiply(Matrix A[], Matrix BT[])
{
    // cout << endl;
    int count = 1;
    Matrix X[MAX_TERM] = {0};
    X[0].rows = A[0].rows;
    X[0].cols = BT[0].cols;

    int num_m = 1;
    int y = A[1].rows;

    for (int i = 1; i <= A[0].value; i++)
    {

        for (int j = 1; j <= BT[0].value; j++)
        {
            if (A[i].cols == BT[j].cols)
            {
                // cout << endl
                //      << "try : " << A[i].rows << " " << A[i].cols << " " << BT[j].rows << " " << BT[j].cols << endl;
                int multi = A[i].value * BT[j].value;

                int flag = 0;

                for (int k = 1; k < num_m; k++)
                {
                    if ((X[k].rows == A[i].rows) && (X[k].cols == BT[j].rows))
                    {
                        X[k].value += multi;
                        flag++;
                        // cout << endl
                        //      << num_m << " " << X[num_m].rows << " " << X[num_m].cols << " " << X[num_m].value << endl;
                        break;
                    }
                }
                if (flag == 0)
                {
                    X[num_m].rows = A[i].rows;
                    X[num_m].cols = BT[j].rows;
                    X[num_m].value += multi;
                    // cout << num_m << " " << X[num_m].rows << " " << X[num_m].cols << " " << X[num_m].value << endl;
                    if (X[num_m].rows == X[num_m - 1].rows) {
                        if (X[num_m].cols <= X[num_m - 1].cols) {
                            int temp = X[num_m].cols;
                            int tempv = X[num_m].value;
                            X[num_m].cols = X[num_m - 1].cols;
                            X[num_m].value = X[num_m - 1].value;
                            X[num_m - 1].cols = temp;
                            X[num_m - 1].value = tempv;
                        }
                    }
                    num_m++;
                }
            }
        }
    }

    X[0].value = num_m - 1;
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
    int aRows = 0, aCols = 0, aValue = 0, bRows = 0, bCols = 0, bValue = 0;

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