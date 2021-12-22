#include <iostream>
using namespace std;

void nhap(int matrix[100][100], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << "nhap vao a[" << i << "][" << j << "]: ";
      cin >> matrix[i][j];
    }
  }
}

void xuat(int matrix[100][100], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

int detMatrix(int matrix[100][100], int n)
{
  int s, sum = 0;
  if (n == 1)
    return matrix[0][0];
  if (n == 2)
    return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
  for (int child = 0; child < n; child++)
  { // tao ma tran con
    int smallMatrix[100][100];
    for (int i = 0; i < n; i++)
    { // xet tung hang
      if (i != child)
      {
        for (int j = 1; j < n; j++)
        {
          if (i < child)
            smallMatrix[i][j - 1] = matrix[i][j];
          else if (i > child)
            smallMatrix[i - 1][j - 1] = matrix[i][j];
        }
      }
    }
    if (child % 2 == 0)
      s = 1;
    else
      s = -1;
    sum += s * matrix[child][0] * detMatrix(smallMatrix, n - 1);
  }
  return sum;
}

int main()
{
  int matrix[100][100], n = 0;
  cout << "nhap n: ";
  cin >> n;
  nhap(matrix, n);
  xuat(matrix, n);
  cout << "detMatrix: " << detMatrix(matrix, n) << endl;
}