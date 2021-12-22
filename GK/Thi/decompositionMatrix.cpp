#include <iostream>
#include <math.h>
#include <list>
#define _default 100
using namespace std;

void MatrixBuild(float Matrix[][_default], int n);
void MatrixRender(float Matrix[][_default], int n);
void inverseMatrix(float Matrix[][_default], int n);
void MatrixMultiply(float result[][_default], float a[][_default], float b[][_default], int n);

int main()
{
    float Matrix[_default][_default];
    float MatrixDiagonal[_default][_default];
    float MatrixV[_default][_default];
    float MatrixResult[_default][_default];
    float MatrixResult2[_default][_default];
    float MatrixInvert[_default][_default];
    float det, trace, eigenvalues1, eigenvalues2;
    float v1, v2, v3;
    MatrixBuild(Matrix, 2);
    det = Matrix[0][0] * Matrix[1][1] - Matrix[0][1] * Matrix[1][0];
    trace = -Matrix[0][0] - Matrix[1][1];
    eigenvalues1 = ((-trace + sqrt((trace * trace) - (4 * det)))) / 2;
    eigenvalues2 = ((-trace - sqrt((trace * trace) - (4 * det)))) / 2;
    cout << "Eigen value 1: " << eigenvalues1 << endl;
    cout << "Eigen value 2: " << eigenvalues2 << endl;
    v1 = (Matrix[0][0] - eigenvalues1);
    v2 = (-Matrix[0][1]);
    v3 = (Matrix[0][0] - eigenvalues2);
    MatrixV[0][0] = v2;
    MatrixV[0][1] = v2;
    MatrixV[1][0] = v1;
    MatrixV[1][1] = v3;
    MatrixDiagonal[0][0] = eigenvalues1;
    MatrixDiagonal[0][1] = 0;
    MatrixDiagonal[1][0] = 0;
    MatrixDiagonal[1][1] = eigenvalues2;
    cout << "Matrix Vector V: " << endl;
    MatrixRender(MatrixV, 2);
    MatrixMultiply(MatrixResult, MatrixV, MatrixDiagonal, 2);
    cout << "Matrix Inverse V ^-1: " << endl;
    inverseMatrix(MatrixV, 2);
    MatrixInvert[0][0] = MatrixV[0][2];
    MatrixInvert[0][1] = MatrixV[0][3];
    MatrixInvert[1][0] = MatrixV[1][2];
    MatrixInvert[1][1] = MatrixV[1][3];
    MatrixMultiply(MatrixResult2, MatrixResult, MatrixInvert, 2);
    cout << "Matrix Result: " << endl;
    MatrixRender(MatrixResult2, 2);
    return 0;
}

void MatrixBuild(float Matrix[][_default], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Matrix [" << i + 1 << "][" << j + 1 << "] : ";
            cin >> Matrix[i][j];
        }
    }
}

void MatrixRender(float Matrix[][_default], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void inverseMatrix(float Matrix[][_default], int n)
{
    float ratio, a;
    // Tạo ma trận đơn vị
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < 2 * n; j++)
        {
            if (i == (j - n))
                Matrix[i][j] = 1.0;
            else
                Matrix[i][j] = 0.0;
        }
    }
    // Tìm hệ số và tính hàng trước theo hệ số
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                ratio = Matrix[j][i] / Matrix[i][i];
                for (int k = 0; k < 2 * n; k++)
                {
                    Matrix[j][k] -= ratio * Matrix[i][k];
                }
            }
        }
    }
    // Biến đổi ma trận theo đường chéo chính
    for (int i = 0; i < n; i++)
    {
        a = Matrix[i][i];
        for (int j = 0; j < 2 * n; j++)
        {
            Matrix[i][j] /= a;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < 2 * n; j++)
        {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void MatrixMultiply(float result[][_default], float a[][_default], float b[][_default], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            float sum = 0;
            for (int k = 0; k < n; k++)
            {
                sum = sum + a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}
