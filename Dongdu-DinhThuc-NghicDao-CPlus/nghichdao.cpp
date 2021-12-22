#include <iostream>
using namespace std;

void nhap(float matrix[100][100], int n)
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

void xuat(float matrix[100][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

float detMatrix(float matrix[100][100], int n)
{
	float s, sum = 0;
	if (n == 1)
		return matrix[0][0];
	if (n == 2)
		return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
	for (int child = 0; child < n; child++)
	{ // tao ma tran con
		float smallMatrix[100][100];
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

float con(float matrix[][100], int n, int hang, int cot)
{ // tinh gia tri phan tu cua ma tran bu
	float b[100][100];
	int i, j, x = -1, y;
	for (i = 0; i < n; i++)
	{
		if (i == hang)
			continue;
		x++;
		y = -1;
		for (j = 0; j < n; j++)
		{
			if (j == cot)
				continue;
			y++;
			b[x][y] = matrix[i][j];
		}
	}
	if ((hang + cot) % 2 == 0)
		return detMatrix(b, n - 1);
	return -detMatrix(b, n - 1);
}

void nghichdao(float matrix[][100], int n)
{
	float b[100][100];
	for (int i = 0; i < n; i++)
	{ // tim ma tran bu
		for (int j = 0; j < n; j++)
		{
			b[i][j] = con(matrix, n, i, j);
		}
	}
	for (int i = 0; i < n - 1; i++)
	{ // chuyen vi
		for (int j = i + 1; j < n; j++)
		{
			float t = b[i][j];
			b[i][j] = b[j][i];
			b[j][i] = t;
		}
	}

	float k = detMatrix(matrix, n);
	if (k == 0)
	{
		cout << "khong co ma tran nghich dao!" << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] /= k;
		}
	}
	xuat(b, n);
}

int main()
{
	float matrix[100][100], n = 0;
	cout << "nhap n: ";
	cin >> n;
	nhap(matrix, n);
	xuat(matrix, n);
	cout << "detMatrix: " << detMatrix(matrix, n) << endl
		 << endl;
	cout << "ma tran nghich dao:" << endl;
	nghichdao(matrix, n);
}