# Neural-Network
神经网络课程作业

课程参考书：[人工神经网络理论、设计及应用第二版](http://product.dangdang.com/20046362.html)

### 1 绪论
本章节无习题

### 2 神经网络基础知识
[basics](https://github.com/tenaghirmb/Neural-Network/tree/master/basics)
1. [activation 激活函数/转移函数](https://github.com/tenaghirmb/Neural-Network/blob/master/basics/activation.py)
  - 双极性阈值型转移函数sgn
  - 单极性S型函数sigmoid及其导数
  - 双极性S型函数bipolar_sigmoid及其导数
2. 神经网络学习规则
  - [hebb学习规则](https://github.com/tenaghirmb/Neural-Network/blob/master/basics/hebb.py)
  - [perceptron学习规则](https://github.com/tenaghirmb/Neural-Network/blob/master/basics/perceptron.py)
  - [![](http://latex.codecogs.com/gif.latex?\delta)学习规则](https://github.com/tenaghirmb/Neural-Network/blob/master/basics/delta.py)
  - [LMS学习规则/Widrow-Hoff学习规则](https://github.com/tenaghirmb/Neural-Network/blob/master/basics/lms.py)

### 3 监督学习神经网络
[supervised](https://github.com/tenaghirmb/Neural-Network/tree/master/supervised)
1. [bpnn.py](https://github.com/tenaghirmb/Neural-Network/blob/master/supervised/bpnn.py) 实现了使用BP算法的神经网络
参考了[Michael Nielsen](http://michaelnielsen.org/)的[代码](http://neuralnetworksanddeeplearning.com/chap1.html)


### 4 竞争学习神经网络
[competitive](https://github.com/tenaghirmb/Neural-Network/tree/master/competitive)
1. [cn.py](https://github.com/tenaghirmb/Neural-Network/blob/master/competitive/cn.py) 实现了一个最基础的竞争学习神经网络
参考了[Masksky](https://github.com/Masksky/competitive-network/blob/master/c_network.py)的代码
