import numpy as np
from math import sqrt
matrix = []

R = int(input("Nhập số hàng:"))
C = int(input("Nhập số cột:"))


def input_output():
    if R == C:
        print("Nhập các phần tử:")
        for i in range(R):
            a = []
            for j in range(C):
                a.append(float(input()))
            matrix.append(a)

        for i in range(R):
            for j in range(C):
                if matrix[i][j] != matrix[j][i]:
                    break
                else:
                    print(matrix[i][j], end=" ")
            print()
    else:
        print("Nhập lại ma trận vuông")


def cholesky_decomposition(arr):
    arr = np.array(arr, float)
    L = np.zeros_like(arr)
    n, _ = np.shape(arr)
    for j in range(n):  # Chỉ số cột
        for i in range(j, n):
            if i == j:
                sumk = 0
                for k in range(j):
                    sumk += L[i, j]**2
                L[i, j] = np.sqrt(arr[i, j]-sumk)
            else:
                sumk = 0
                for k in range(j):
                    sumk += L[i, k]*L[j, k]
                L[i, j] = (arr[i, j]-sumk)/(L[j, j])

    return L


def check(arr):
    for i in range(len(arr)):
        if arr[i] > 0:
            return True
        return False


if __name__ == "__main__":
    input_output()

    a = np.array(matrix)
    v = np.linalg.eigvals(np.array(matrix))

    print('----Matrix A: ----\n' + str(a) + '\n')
    print('----Matrix V: ---- \n' + str(v) + '\n')

    if check(v) == True:
        L = cholesky_decomposition(a)
        LL = np.dot(L, np.transpose(L))
        print('----Matrix L: ---- \n' + str(L) + '\n')
        print('----Matrix LL: --- \n' + str(LL) + '\n')
    else:
        print('Không tìm được L')
