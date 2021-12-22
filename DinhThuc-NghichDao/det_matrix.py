
n = int(input("Nhập kích cỡ ma trận:"))
matrix = []


def _input():
    print("Nhập các phần tử:")
    for i in range(n):
        a = []
        for j in range(n):
            a.append(int(input()))
        matrix.append(a)


def _output():
    for i in range(n):
        for j in range(n):
            print(matrix[i][j], end=" ")
        print()


def detOfMatrix(mat, n):
    temp = [0]*n
    total = 1
    det = 1
    for i in range(0, n):
        index = i

        while(mat[index][i] == 0 and index < n):
            index += 1

        if(index == n):
            continue

        if(index != i):

            for j in range(0, n):
                mat[index][j], mat[i][j] = mat[i][j], mat[index][j]
            det = det*int(pow(-1, index-i))

        for j in range(0, n):
            temp[j] = mat[i][j]

        for j in range(i+1, n):
            num1 = temp[i]
            num2 = mat[j][i]

            for k in range(0, n):
                mat[j][k] = (num1*mat[j][k]) - (num2*temp[k])

            total = total * num1  # Det(kA)=kDet(A);

    for i in range(0, n):
        det = det*mat[i][i]

    return int(det/total)  # Det(kA)/k=Det(A);


_input()
_output()
print("Determinant of the matrix is : ", detOfMatrix(matrix, n))
