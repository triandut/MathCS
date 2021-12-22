import numpy as np


def sgrad(w, i, rd_id):
    true_i = rd_id[i]
    xi = Xbar[true_i, :]
    yi = y[true_i]
    a = np.dot(xi, w) - yi
    return (xi*a).reshape(2, 1)


def SGD(w_init, sgrad, eta):
    w = [w_init]
    w_last_check = w_init
    iter_check_w = 10
    N = X.shape[0]
    count = 0
    for it in range(1000):
        # shuffle data
        rd_id = np.random.permutation(N)
        for i in range(N):
            count += 1
            g = sgrad(w[-1], i, rd_id)
            w_new = w[-1] - eta*g
            w.append(w_new)
            if count % iter_check_w == 0:
                w_this_check = w_new
                if np.linalg.norm(w_this_check - w_last_check)/len(w_init) < 1e-3:
                    return (w, i)
                w_last_check = w_this_check
    return (w, i)


if __name__ == '__main__':
    X = np.random.rand(1000, 1)
    y = 4 + 3 * X + .2*np.random.randn(1000, 1)  # noise added

  # Building Xbar
    one = np.ones((X.shape[0], 1))
    Xbar = np.concatenate((one, X), axis=1)
  # SGD
    init = np.array([[2], [1]])
    (w1, i1) = SGD(init, sgrad, 0.01)
    print('Stochastic Gradient Descent: w = ',
          w1[-1].T, ',\n after %d iterations.' % (i1+1))
