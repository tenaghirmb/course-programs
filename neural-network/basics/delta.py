# -*- coding: utf-8 -*-
# @Author: aka
# @Date:   2019-03-16 21:03:03
# @Last Modified by:   aka
# @Last Modified time: 2019-03-16 21:23:17
# @Email: tenag_hirmb@hotmail.com

import numpy as np
from activation import bipolar_sigmoid, bipolar_sigmoid_derivative

eta = 0.25
w0 = np.array([1, 0, 1])
x = np.array([[2, 0, -1],
              [1, -2, -1]])
d = np.array([-1, 1])
activate_f = bipolar_sigmoid
activate_d = bipolar_sigmoid_derivative


def delta_step(sample, label, w, f, df):
    net = w.dot(sample)
    derivative = df(net)
    o = f(net)
    deltaw = eta * (label - o) * derivative * sample
    new_w = w + deltaw
    return net, o, derivative, new_w


def main():
    n = x.shape[0]
    w = w0
    for i in range(n):
        net, o, derivative, w = delta_step(x[i], d[i], w, activate_f, activate_d)
        print(f'step {i+1}: net = {net}\n        o = {o}\n        f\'={derivative}\n        w = {w}')


if __name__ == '__main__':
    main()
