
import math
import copy

# Một class để biểu diễn một Điểm trong mặt phẳng 2D


class Point():
    def __init__(self, x, y):
        self.x = x
        self.y = y

# Tìm khoảng cách giữa 2 điểm


def dist(p1, p2):
    return math.sqrt((p1.x - p2.x) *
                     (p1.x - p2.x) +
                     (p1.y - p2.y) *
                     (p1.y - p2.y))

# Hàm BruteForce để trả về
# khoảng cách nhỏ nhất giữa hai điểm
# trong P [] có kích thước n


def bruteForce(P, n):
    min_val = float('inf')
    for i in range(n):
        for j in range(i + 1, n):
            if dist(P[i], P[j]) < min_val:
                min_val = dist(P[i], P[j])

    return min_val

# Hàm tìm khoảng cách giữa các điểm gần nhất của dải có kích thước nhất định.
# Tất cả các điểm trong dải mảng được sắp xếp theo tọa độ y.
# Tất cả chúng đều có giới hạn trên,
# trên khoảng cách tối thiểu là d


def stripClosest(strip, size, d):
    min_val = d  # Khởi tạo khoảng cách tối thiểu là d
    # Lặp lần lượt tất cả các điểm và
    # thử các điểm tiếp theo cho đến khi chênh lệch giữa các tọa độ y nhỏ hơn d
    for i in range(size):
        j = i + 1
        while j < size and (strip[j].y -
                            strip[i].y) < min_val:
            min_val = dist(strip[i], strip[j])
            j += 1

    return min_val

# Hàm đệ quy để tìm khoảng cách nhỏ nhất.
# Mảng P chứa tất cả các điểm được sắp xếp theo tọa độ x


def closestUtil(P, Q, n):

    if n <= 3:
        return bruteForce(P, n)

    # Tìm điểm ở giữa
    mid = n // 2
    midPoint = P[mid]

    Pl = P[:mid]
    Pr = P[mid:]

    # Xét đường thẳng đứng đi qua điểm giữa,
    # Tính khoảng cách nhỏ nhất dl ở bên trái của điểm giữa và dr ở bên phải
    dl = closestUtil(Pl, Q, mid)
    dr = closestUtil(Pr, Q, n - mid)

    # Tìm min dr và dl
    d = min(dl, dr)
    # Xây dựng một mảng stripP[] chứa điểm gần (gần hơn d) với đường thẳng đi qua điểm giữa
    stripP = []
    stripQ = []
    lr = Pl + Pr
    for i in range(n):
        if abs(lr[i].x - midPoint.x) < d:
            stripP.append(lr[i])
        if abs(Q[i].x - midPoint.x) < d:
            stripQ.append(Q[i])

    stripP.sort(key=lambda point: point.y)  # <-- REQUIRED
    min_a = min(d, stripClosest(stripP, len(stripP), d))
    min_b = min(d, stripClosest(stripQ, len(stripQ), d))

    return min(min_a, min_b)

# Hàm chính tìm khoảng cách nhỏ nhất.


def closest(P, n):
    P.sort(key=lambda point: point.x)
    Q = copy.deepcopy(P)
    Q.sort(key=lambda point: point.y)

    return closestUtil(P, Q, n)


P = [Point(2, 3), Point(12, 30),
     Point(40, 50), Point(5, 1),
     Point(12, 10), Point(3, 4)]
n = len(P)
print("Khoảng cách nhỏ nhất là",
      closest(P, n))
