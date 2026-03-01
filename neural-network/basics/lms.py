# -*- coding: utf-8 -*-
# @Author: aka
# @Date:   2019-03-16 21:32:07
# @Last Modified by:   aka
# @Last Modified time: 2019-03-16 21:48:32
# @Email: tenag_hirmb@hotmail.com

import numpy as np

eta = 0.25
w0 = np.array([1, 0, 1])
x = np.array([[2, 0, -1],
              [1, -2, -1]])
d = np.array([-1, 1])


def lms_step(sample, label, w):
    net = w.dot(sample)
    deltaw = eta * (label - net) * sample
    new_w = w + deltaw
    return net, new_w


def main():
    n = x.shape[0]
    w = w0
    for i in range(n):
        net, w = lms_step(x[i], d[i], w)
        print(f'step {i+1}: net = {net}\n        w = {w}')


if __name__ == '__main__':
    main()
