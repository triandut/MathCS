import numpy as np

def Danhilepski_Method(a):
    n = len(a)
    m = np.identity(n)

    for k in range(n - 2, -1, -1):
        M = np.identity(n) 
        M1 = np.identity(n)
        M1[k] = a[k+1]
        M[k] = -a[k+1] / a[k+1][k]
        M[k][k] = 1 / a[k+1][k]
        m = m.dot(M)
        a = M1.dot(a.dot(M))

    p = [1] + [-i for i in a[0]]
    eigenvalues = np.roots(p)
    y = np.array([[lamda**(n-1-i) for i in range(n)] for lamda in eigenvalues]).T
    eigenvectors = m.dot(y)

    return eigenvalues, eigenvectors
   
def main():
    A = np.array([
    [5.2, 3, 10],
    [3, 6.3, 4],
    [0.5, -2, 3],
    ])
    
    print("Matrix A\n", A, "\n")
    lamda, v = Danhilepski_Method(A)
    print("Eigenvalues lamda\n", lamda, "\n")
    print("Eigenvectors V\n",v, "\n")
    print("V.diag(lamda).V^-1\n", v.dot(np.diag(lamda)).dot(np.linalg.inv(v)))

if __name__ == '__main__':
    main()