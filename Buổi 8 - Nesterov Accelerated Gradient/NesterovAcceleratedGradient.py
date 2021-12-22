import math
import numpy as np
import matplotlib.pyplot as plt


def cost(x):
    return x**2 + 10*np.sin(x)


def grad(x):
    return 2*x + 10*np.cos(x)


def NAG(theta_init, alpha=0.1, beta=0.9, Loop=1000):
    theta = [theta_init]
    v_old = np.zeros_like(theta_init)
    for it in range(Loop):
        v_new = beta*v_old + alpha*grad(theta[-1] - beta*v_old)
        theta_new = theta[-1] - v_new
        theta.append(theta_new)
        v_old = v_new
    return (theta, it)


def myGD1(alpha, x0, gra=1e-3, loop=1000):
    x = [x0]
    for i in range(loop):
        x_new = x[-1] - alpha*grad(x[-1])
        if abs(grad(x_new)) < gra:
            break
        x.append(x_new)
    return (x, i)


if __name__ == '__main__':
    X = np.linspace(-5, 5, 200)
    y = cost(X)
    plt.plot(X.T, y.T, 'r.')
    plt.axis([-5, 5, -10, 15])
    (x1, it1) = myGD1(5, 0.1)
    print('Solution x1 = %f, cost = %f, obtained after %d iterations' %
          (x1[-1], cost(x1[-1]), it1))
    plt.plot(x1[-1], cost(x1[-1]), 'r X')
    (x2, it2) = NAG(5, 0.1, beta=0.9)
    print('GDA Solution x2 = %f, cost = %f, obtained after %d iterations' %
          (x2[-1], cost(x2[-1]), it2))
    plt.plot(x2[-1], cost(x2[-1]), 'r X')
    plt.show()
