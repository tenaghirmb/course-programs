# -*- coding: utf-8 -*-
# @Author: aka
# @Date:   2019-03-16 20:23:19
# @Last Modified by:   aka
# @Last Modified time: 2019-03-16 20:55:09
# @Email: tenag_hirmb@hotmail.com

import numpy as np
from activation import sgn

eta = 1
w0 = np.array([0, 1, 0])
x = np.array([[2, 1, -1],
              [0, -1, -1]])
d = np.array([-1, 1])
loss_theta = 0
activate_f = sgn


def perceptron_step(sample, label, w, f):
    net = w.dot(sample)
    error = label - f(net)
    deltaw = eta * (error) * sample
    new_w = w + deltaw
    return net, new_w, error


def perceptron_learn(data, label):
    loss = 99
    epoch = 1
    w = w0
    n = data.shape[0]
    while loss > loss_theta:
        loss = 0
        print(f'\nepoch {epoch}')
        epoch += 1
        for i in range(n):
            net, w, error = perceptron_step(data[i], label[i], w, activate_f)
            loss += abs(error)
            print(f'step {i+1}: net={net}\n        w = {w}\n        error={error}')
    return None


def main():
    perceptron_learn(x, d)


if __name__ == '__main__':
    main()
