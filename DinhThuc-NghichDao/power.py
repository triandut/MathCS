def power(a, m, n):
    res = 1
    if (a == 0):
        return 0
    while (m > 0):
        if ((m & 1) == 1):
            res = (res * (a % n)) % n
        m = m >> 1
        print("m: ", m)
        a = (a * a) % n
        print("a: ", (a * a))
        print("res: ", res)
        
    return res


print("Nhap a: ")
a = int(input())
print("Nhap m:")
m = int(input())
print("Nhap n :")
n = int(input())
print("Ket qua = ", power(a, m, n))
