import math
from copy import deepcopy


def norm(x=[]):
    temp = 0.0
    for i in range(0, len(x)):
        temp += x[i] * x[i]
    return math.sqrt(temp)


def distance(x=[], y=[]):
    temp = []
    for i in range(0, len(x)):
        temp.append(x[i] - y[i])
    return norm(temp)


def SOR(XO1=[], a=[[]], b=[], TOL=0.01, N=100, w=0.0):
    XO = deepcopy(XO1)
    k = 1
    x = []
    for i in range(0, len(a)):
        x.append(0.0)
    while k <= N:
        for i in range(0, len(a)):
            temp0 = 0.0
            temp1 = 0.0
            for j in range(0, i):
                temp0 += a[i][j] * x[j]
            for j in range(i + 1, len(a)):
                temp1 += a[i][j] * XO[j]

            temp = (w * ((-1) * (temp1 + temp0) + b[i])) / a[i][i]
            x[i] = (1 - w) * XO[i] + temp
        # print(x)
        if distance(x, XO) < TOL:
            return x

        k = k + 1
        for i in range(0, len(a)):
            XO[i] = x[i]


a = [[4, 3, 0], [3, 4, -1], [0, -1, 4]]
b = [24, 30, -24]
x0 = [1, 1, 1]

z = SOR(x0, a, b, 0.00001, 100, 1.25)
print(z)

ea = [
    [4, 1, 1, 0, 1],
    [-1, -3, 1, 1, 0],
    [2, 1, 5, -1, -1],
    [-1, -1, -1, 4, 0],
    [0, 2, -1, 1, 4],
]
eb = [6, 6, 6, 6, 6]
ex = [0, 0, 0, 0, 0]
ez = SOR(ex, ea, eb, 0.00001, 100, 1.1)
ez1 = SOR(ex, ea, eb, 0.00001, 100, 1.3)
print("e:")
print("w=1.1 :" + str(ez))
print("w=1.3 :" + str(ez1))


fa = [
    [4, -1, 0, -1, 0, 0],
    [-1, 4, -1, 0, -1, 0],
    [0, -1, 4, 0, 0, -1],
    [-1, 0, 0, 4, -1, 0],
    [0, -1, 0, -1, 4, -1],
    [0, 0, -1, 0, -1, 4],
]

fb = [0, 5, 0, 6, -2, 6]

fx = [0, 0, 0, 0, 0, 0]
fz = SOR(fx, fa, fb, 0.00001, 100, 1.1)
fz1 = SOR(fx, fa, fb, 0.00001, 100, 1.3)
print("f:")
print("w=1.1" + str(fz))
print("w=1.3" + str(fz1))
