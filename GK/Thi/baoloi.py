class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


def Left_index(points):

    # Tìm điểm xa nhất bên trái

    minn = 0
    for i in range(1, len(points)):
        if points[i].x < points[minn].x:
            minn = i
        elif points[i].x == points[minn].x:
            if points[i].y > points[minn].y:
                minn = i
    return minn

# Tìm hướng của ba điểm liên tiếp


def orientation(p, q, r):

    val = (q.y - p.y) * (r.x - q.x) - \
          (q.x - p.x) * (r.y - q.y)

    if val == 0:
        return 0
    elif val > 0:
        return 1
    else:
        return 2


def convexHull(points, n):

    # Có ít nhất 3 điểm
    if n < 3:
        return

    # Tìm điểm ngoài cùng bên trái
    l = Left_index(points)

    hull = []

    p = l
    q = 0
    while(True):

        # Add điểm hiện tại vào mảng
        hull.append(p)
        q = (p + 1) % n

        for i in range(n):

            # Cập nhật điểm q nếu i lớn hơn q hiện tại
            if(orientation(points[p],
                           points[i], points[q]) == 2):
                q = i

        p = q

        if(p == l):
            break

    for each in hull:
        print(points[each].x, points[each].y)


points = []

points.append(Point(1, 2))
points.append(Point(2, 5))
points.append(Point(3, 4))
points.append(Point(4, 3))
points.append(Point(5, 4))
points.append(Point(6, 1))
points.append(Point(7, 5))

convexHull(points, len(points))
