import numpy as np

from numpy import linalg as LA
from math import sqrt


def calcD(a):  # tinh calcD
    D = np.zeros_like(a)
    aaT = np.dot(a, np.transpose(a))
    rank = np.linalg.matrix_rank(a)  # bac cua ma tran A
    v = np.linalg.eigvals(aaT)  # v: gia tri rieng cua A*A^T
    for i in range(rank):
        D[i, i] = sqrt(v[i])
    return D


if __name__ == '__main__':

    m, n = 5, 4

    A = np.array([[3, 1, 0], [1,
                 2, 2], [0, 1, 1]])
# -0.997497 0.617481 -0.299417
# 0.127171 0.170019 0.791925
# -0.613392 -0.0402539 0.64568
    U, S, V = LA.svd(A)
    D = calcD(A)
    I = np.dot(U, D)
    K = np.dot(I, V)

    print('----- Matrix A: -----\n' + str(np.array(A)) + '\n')

    print('----- Matrix U: -----\n' + str(U) + '\n')

    print('----- Matrix S: -----\n' + str(S) + '\n')

    print('----- Matrix V: -----\n' + str(V) + '\n')

    print('----- Matrix KQ: -----\n' + str(K) + '\n')


# def calcU(a):  # tinh U
#     aaT = np.dot(a, np.transpose(a))
#     w, v = np.linalg.eig(aaT)
#     return np.transpose(v)


# def calcV(a):  # tinh V^T
#     aTa = np.dot(np.transpose(a), a)
#     w, V = np.linalg.eig(aTa)
#     return V


# def calcD(a):  # tinh calcD
#     D = np.zeros_like(a)
#     aaT = np.dot(a, np.transpose(a))
#     rank = np.linalg.matrix_rank(a)  # bac cua ma tran A
#     v = np.linalg.eigvals(aaT)  # v: gia tri rieng cua A*A^T
#     for i in range(rank):
#         D[i, i] = sqrt(v[i])
#     return D


# if __name__ == '__main__':
#     A = np.array([[1, 2], [3, 4], [5, 6]])
#     U = calcU(A)
#     V = calcV(A)
#     D = calcD(V)
#     print('---Matrix U: ---- \n'+str(U) + '\n')
#     print('---Matrix V: ---- \n'+str(V) + '\n')
#     print('---Matrix D: ---- \n'+str(D) + '\n')
#     # calcV(A)
#     # calcD(A)
