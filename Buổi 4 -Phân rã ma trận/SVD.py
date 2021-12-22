import numpy as np
from math import sqrt

matrix = []

R = int(input("Nhập số hàng:"))
C = int(input("Nhập số cột:"))


def input_output():
    print("Nhập từng phần tử:")

    for i in range(R):
        a = []
        for j in range(C):
            a.append(float(input()))
        matrix.append(a)

    for i in range(R):
        for j in range(C):
            print(matrix[i][j], end=" ")
        print()


def build_U():  # Dựng ma trận U
    a = np.array(matrix)  # Ma trận A
    a_Transpose = np.transpose(a)  # Ma trận A^T
    b = np.dot(a, a_Transpose)  # Ma trận A*A^T
    w, v = np.linalg.eig(b)
    return v


def build_V():  # Dựng ma trận V
    a = np.array(matrix)  # Ma trận A
    a_Transpose = np.transpose(a)  # Ma trận A^T
    b = np.dot(a_Transpose, a)  # Ma trận A^T*A
    w, v = np.linalg.eig(b)
    return np.transpose(v)


def build_D():  # Dựng ma trận D
    a = np.array(matrix)
    D = np.zeros_like(a)  # Tạo ma trận 0 D bằng rank ma trận A
    AA_Tranpose = np.dot(a, np.transpose(a))  # Ma trận AA^T
    rank = np.linalg.matrix_rank(a)
    v = np.linalg.eigvals(AA_Tranpose)  # Tìm vecto riêng A*A^T
    for i in range(rank):
        D[i, i] = sqrt(v[i])
    return D


if __name__ == '__main__':
    input_output()
    U = np.array(build_U())
    V = np.array(build_V())
    D = np.array(build_D())
    print('---MATRIX U:--- \n' + str(U) + '\n')
    print('---MATRIX V^T:--- \n' + str(V) + '\n')
    print('---MATRIX D:--- \n' + str(D) + '\n')
