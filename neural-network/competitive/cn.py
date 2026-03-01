#! /usr/bin/env python
# -*- coding: utf-8 -*-

"""
@author: aka
@file: cn.py
@time: 2019-04-06 15:49
@contact: tenag_hirmb@hotmail.com
"""

from sklearn.preprocessing import normalize
import numpy as np
import sys
sys.path.append('..')


def cart2pol(x, y):
    rho = np.sqrt(x**2 + y**2)
    phi = np.arctan2(y, x) * 180 / np.pi
    return(rho, phi)


class CN(object):
    """
    competitive network
    """

    def __init__(self, sizes, alpha, weights=None):
        self.sizes = sizes
        self.alpha = alpha
        self.weights = weights
        if weights is None:
            self.weights = np.random.randn(sizes[1], sizes[0])
        self.weights = normalize(weights)

    def forward_propagation(self, x):
        x = x.reshape(1, x.shape[0])
        z = np.dot(self.weights, x.T)
        argmax = np.where(z == np.amax(z))[0][0]
        return argmax

    def update_weights(self, argmax, x):
        self.weights[argmax] = self.weights[argmax] + \
            self.alpha * (x - self.weights[argmax])
        self.weights[argmax] = normalize(
            self.weights[argmax].reshape(
                1, self.weights[argmax].shape[0]))[0]

    def train(self, X, epochs):
        X = np.array(X)
        X = normalize(X)
        if self.sizes[0] == 2:
            for x in X:
                print(cart2pol(x[0], x[1])[1])
            print("")
            for weight in self.weights:
                print(cart2pol(weight[0], weight[1])[1], end="\t")
            print("\n")
        for j in range(epochs):
            print(f"Epoch {j} starts")
            for x in X:
                argmax = self.forward_propagation(x)
                self.update_weights(argmax, x)
                # print(self.weights)
                if self.sizes[0] == 2:
                    for weight in self.weights:
                        print(cart2pol(weight[0], weight[1])[1], end="\t")
                    print("")
            print(f"Epoch {j} complete\n")

    def predict(self, x):
        argmax = self.forward_propagation(x)
        return argmax
