from __future__ import division, print_function, unicode_literals
import math
import numpy as np


def cost(x):  # Hàm f(x)
    return (np.exp(-x) - 2/(np.exp(x)))*(np.exp(-x) - 2/(np.exp(x)))


def grad(x):  # Đạo hàm f(x)
    return -2*(np.exp(-2*x))


def myGD1(alpha, x0, gra=1e-3, loop=1000):
    x = [x0]
    for i in range(loop):
        x_new = x[-1] - alpha*grad(x[-1])
        if abs(grad(x_new)) < gra:
            break

        x.append(x_new)

    return (x, i)


if __name__ == '__main__':

    (x1, it1) = myGD1(.01, -2)
    print('Solution x1 = %f, cost = %f, obtained after %d iterations' %
          (x1[-1], cost(x1[-1]), it1))
