# -*- coding: utf-8 -*-
# @Author: aka
# @Date:   2019-03-16 20:17:28
# @Last Modified by:   AKA
# @Last Modified time: 2019-04-01 22:23:04
# @Email: tenag_hirmb@hotmail.com
import numpy as np


def sgn(net):
    if net >= 0:
        return 1
    else:
        return -1


def bipolar_sigmoid(net):
    return (1.0 - np.exp(-net)) / (1.0 + np.exp(-net))


def bipolar_sigmoid_derivative(net):
    out = bipolar_sigmoid(net)
    return 0.5 * (1 - out * out)


def sigmoid(net):
    return 1.0 / (1.0 + np.exp(-net))


def sigmoid_derivative(net):
    return sigmoid(net) * (1 - sigmoid(net))
