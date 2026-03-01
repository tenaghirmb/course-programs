# -*- coding: utf-8 -*-
# @Author: aka
# @Date:   2019-03-16 19:33:50
# @Last Modified by:   aka
# @Last Modified time: 2019-03-16 20:19:13
# @Email: tenag_hirmb@hotmail.com

import numpy as np
from activation import *

eta = 1
activate_f = bipolar_sigmoid
w0 = np.array([1, -1])
data = np.array([[1, -2],
                 [0, 1],
                 [2, 3],
                 [1, -1]])


def hebb_learn(sample, w, f):
    net = w.dot(sample)
    deltaw = eta * f(net) * (sample)
    new_w = w + deltaw
    return net, new_w


def main():
    n = data.shape[0]
    w = w0
    for i in range(n):
        net, w = hebb_learn(data[i], w, activate_f)
        print(f'step {i+1}: net = {net}\n        w = {w}')


if __name__ == '__main__':
    main()
