#! /usr/bin/env python
# -*- coding: utf-8 -*-

"""
@author: aka
@file: BPnetwork.py
@time: 2019-04-03 17:54
@contact: tenag_hirmb@hotmail.com
"""

from supervised.bpnn import BPNN
import numpy as np


def main():
    epochs = 1
    mini_batch_size = 1
    eta = 1  # learning rate
    V0 = np.array([[1, -2], [2, 0]])
    W0 = np.array([[1, 0], [1, -2]])
    d = np.array([[0.95, 0.05]]).T
    X = np.array([[1, 3]]).T
    by = np.array([[-3], [1]])
    bo = np.array([[2], [-3]])

    network = BPNN([2, 2, 2], [by, bo], [V0, W0])
    network.SGD([(X, d)], epochs, mini_batch_size, eta)


if __name__ == '__main__':
    main()
