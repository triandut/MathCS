from __future__ import division, print_function, unicode_literals
import math
import numpy as np


def cost(x):
    return (math.e**(-x) - 2/(math.e**x))**2


def grad(x):
    return -2*math.e**(-2*x)


def myGD1(alpha, x0, gra=1e-3, loop=1000):
    x = [x0]
    for i in range(loop):
        x_new = x[-1] - alpha*grad(x[-1])
        if abs(grad(x_new)) < gra:
            break

        x.append(x_new)

    return (x, i)


if __name__ == '__main__':

    # (x1, it1) = myGD1(.05, 1)
    # print('Solution x4 = %f, cost = %f, obtained after %d iterations' %
    #       (x1[-1], cost(x1[-1]), it1))
    (x1, it1) = myGD1(.01, -2)

    (x2, it2) = myGD1(.01, -1)

    print('Solution x1 = %f, cost = %f, obtained after %d iterations' %
          (x1[-1], cost(x1[-1]), it1))

    print('Solution x2 = %f, cost = %f, obtained after %d iterations' %
          (x2[-1], cost(x2[-1]), it2))
    (x3, it3) = myGD1(.01, -2)

    print('Solution x3 = %f, cost = %f, obtained after %d iterations' %
          (x3[-1], cost(x3[-1]), it3))
    (x4, it4) = myGD1(.01, 1)
    print('Solution x4 = %f, cost = %f, obtained after %d iterations' %
          (x4[-1], cost(x4[-1]), it4))
