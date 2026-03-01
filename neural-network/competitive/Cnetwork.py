#! /usr/bin/env python
# -*- coding: utf-8 -*-

"""
@author: aka
@file: Cnetwork.py
@time: 2019-04-06 15:51
@contact: tenag_hirmb@hotmail.com
"""

from competitive.cn import CN
import numpy as np


def main():
    epoch = 10
    alpha = 0.25  # learning rate
    w = np.array([[np.sqrt(2), 0], [0, np.sqrt(2)]])
    X = np.array([[1, -1], [1, 1], [-1, -1]])

    network = CN([w.shape[1], w.shape[0]], alpha, w)
    network.train(X, epoch)


if __name__ == '__main__':
    main()
