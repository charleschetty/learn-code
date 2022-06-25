import math
import sympy
from sympy import symbols
import hwk1
import sys
sys.path.append('/home/charles/Documents/code/hwk/homework4/1.py')


t, y = symbols('t y')

expr = y-t*t+1

# hwk1.euler_method(expr, 0, 2, 0.5, 10)
# hwk1.taylor_method(expr, 0, 2, 0.5, 10, 4)

# hwk1.mid_point_method(expr, 0, 2, 0.5, 10)
# hwk1.modi_euler_method(expr, 0, 2, 0.5, 10)
# hwk1.heun_method(expr, 0, 2, 0.5, 10)
# hwk1.runge_kutta_method_four(expr, 0, 2, 0.5, 10)


def fun_test(x):
    return (x+1)**2-0.5*math.exp(x)


fun_val = []
for i in range(0, 6):
    fun_val.append(fun_test(0.2*i))

# # print(fun_val)
# hwk1.adams_bash_two(expr, 0, 2, fun_val[0], fun_val[1], 10)
# hwk1.adams_bash_three(expr, 0, 2, fun_val[0], fun_val[1], fun_val[2], 10)
# hwk1.adams_bash_four(expr, 0, 2, fun_val[0], fun_val[1], fun_val[2], fun_val[3], 10)
# hwk1.adams_bash_five(expr, 0, 2, fun_val[0], fun_val[1], fun_val[2], fun_val[3], fun_val[4], 10)
# hwk1.adams_four_oder_pc(expr, 0, 2, 0.5, 10)


# alpha_of_fun=[0,0]
# def fun1(t1, vec):
#     return -4*vec[0]+3*vec[1]+6

# def fun2(t1, vec):
#     return -2.4*vec[0]+1.6*vec[1]+3.6

# fun_12=[fun1, fun2]

# hwk1.runge_kutta_sys_diff_equ(0, 0.5, fun_12, alpha_of_fun, 5)

# def fun_k1(t1, vec):
#     return vec[1]

# def fun_k2(t1, vec):
#     return math.exp(2*t1)*math.sin(t1)-2*vec[0]+2*vec[1]

# fun_k12=[fun_k1,fun_k2]
# alpk=[-0.4,-0.6]
# hwk1.runge_kutta_sys_diff_equ(0, 1, fun_k12, alpk, 10)

# fun7 = -y+t+1

# # print(fun7.subs(t,0).subs(y,0))
# hwk1.euler_method(fun7, 0, 5, 1, 25)
# hwk1.euler_method(fun7, 0, 5, 1, 50)
# hwk1.euler_method(fun7, 0, 5, 1, 100)

fun4c = -(y+1)*(y+3)


def real_fun4c(x):
    return -3+2/(1+math.exp(-2*x))
# hwk1.modi_euler_method(fun4c, 0, 2, -2, 10)
# print(real_fun4c(2))

# def liner(x1,y1,x2,y2):
#     k = (y2-y1)/(x2-x1)
#     b = y1-k*x1
#     def fun1(x):
#         return k*x+b
#     return fun1


# print(liner(1.2, -1.1722, 1.4, -1.12008)(1.3), real_fun4c(1.3))
# print(liner(1.8, -1.05717, 2.0, -1.03919)(1.93), real_fun4c(1.93))

# hwk1.heun_method(fun4c, 0 , 2, -2, 10)
# print(real_fun4c(2))

# print(liner(1.2, -1.16999323088721, 1.4, -1.11836177932903)(1.3), real_fun4c(1.3))
# print(liner(1.8, -1.05625058113905, 2.0, -1.03854252366502)(1.93), real_fun4c(1.93))

# hwk1.mid_point_method(fun4c, 0, 2, -2, 10)
# print(real_fun4c(2))

# print(liner(1.2, -1.16889758797353, 1.4, -1.11751648737120)(1.3), real_fun4c(1.3))
# print(liner(1.8, -1.05579872156681, 2.0, -1.03822269715153)(1.93), real_fun4c(1.93))

# hwk1.runge_kutta_method_four(fun4c, 0, 2, -2, 10)
# print(real_fun4c(2))

# fun4creal = -3+2/(1+sympy.exp(-2*t))
# print(fun4creal.diff().subs(t,1.0))
# print(fun4creal.diff().subs(t,1.2))
# print(fun4creal.diff().subs(t,1.4))


# print(fun4creal.diff().subs(t,1.6))
# print(fun4creal.diff().subs(t,1.8))
# print(fun4creal.diff().subs(t,2.0))

# hwk1.runge_kutta_method_four(fun4c, 0, 2, -2, 10)

fun_val_of_rk = [-2, -1.80262739207947, -
                 1.62005763880431, -1.46296283879001, -1.33598238271148]

# hwk1.adams_bash_two(fun4c, 0, 2, fun_val_of_rk[0], fun_val_of_rk[1], 10)
# hwk1.adams_bash_three(fun4c, 0, 2, fun_val_of_rk[0], fun_val_of_rk[1], fun_val_of_rk[2], 10)
# hwk1.adams_bash_four(fun4c, 0, 2, fun_val_of_rk[0], fun_val_of_rk[1], fun_val_of_rk[2], fun_val_of_rk[3], 10)
# hwk1.adams_bash_five(fun4c, 0, 2, fun_val_of_rk[0], fun_val_of_rk[1], fun_val_of_rk[2], fun_val_of_rk[3], fun_val_of_rk[4], 10)
# print("real val:",real_fun4c(2))
# hwk1.adams_four_oder_pc(fun4c, 0, 2, -2, 10)

# def adams_four_oder_pc_p(fun, a, b, alpha, N, p):
#     h = (b-a)/N
#     t_temp = [a]
#     w_temp = [alpha]

#     for i in range(1, 4):
#         K1 = h*fun.subs(t, t_temp[i-1]).subs(y, w_temp[i-1])
#         K2 = h*fun.subs(t, t_temp[i-1]+(h/2)).subs(y, w_temp[i-1]+(K1/2))
#         K3 = h*fun.subs(t, t_temp[i-1]+(h/2)).subs(y, w_temp[i-1]+(K2/2))
#         K4 = h*fun.subs(t, t_temp[i-1]+h).subs(y, w_temp[i-1]+K3)

#         wi = w_temp[i-1]+(K1+2*K2+2*K3+K4)/6
#         w_temp.append(wi)
#         t_temp.append(a+i*h)

#     for i in range(4, N+1):
#         t_this = a+i*h
#         w_this = w_temp[3]+h*(55*fun.subs(t, t_temp[3]).subs(y, w_temp[3])
#             -59*fun.subs(t, t_temp[2]).subs(y, w_temp[2])
#             +37*fun.subs(t, t_temp[1]).subs(y, w_temp[1])
#             -9*fun.subs(t, t_temp[0]).subs(y, w_temp[0]))/24


#         w = w_temp[3]+h*(9*fun.subs(t, t_this).subs(y, w_this)
#             +19*fun.subs(t, t_temp[3]).subs(y, w_temp[3])
#             -5*fun.subs(t, t_temp[2]).subs(y, w_temp[2])
#             +fun.subs(t, t_temp[1]).subs(y, w_temp[1]))/24

#         for j in range(0,p-1):
#             w = w_temp[3]+h*(9*fun.subs(t, t_this).subs(y, w)
#                 +19*fun.subs(t, t_temp[3]).subs(y, w_temp[3])
#                 -5*fun.subs(t, t_temp[2]).subs(y, w_temp[2])
#                 +fun.subs(t, t_temp[1]).subs(y, w_temp[1]))/24

#         for j in range(0, 3):
#             t_temp[j] = t_temp[j+1]
#             w_temp[j] = w_temp[j+1]
#         w_temp[3] = w
#         t_temp[3] = t_this

#     print(w_temp[3], p)

# for i in range(2,5):

#     adams_four_oder_pc_p(fun4c, 0, 2, -2, 10, i)

alpha_of_fun_sys = [1, 2, 0]


def fun1_sys(t1, vec):
    return vec[1]


def fun2_sys(t1, vec):
    return vec[2]


def fun3_sys(t1, vec):
    return math.exp(t1)+2*vec[0]+vec[1]-2*vec[2]


fun_12 = [fun1_sys, fun2_sys, fun3_sys]

hwk1.runge_kutta_sys_diff_equ(0, 3, fun_12, alpha_of_fun_sys, 15)


def autual_fun_sys(x):
    return 43*math.exp(x)/36+math.exp(-x)/4-4*math.exp(-2*x)/9+x*math.exp(x)/6


autual_fun_sys1 = 43*sympy.exp(t)/36+sympy.exp(-t) / \
    4-4*sympy.exp(-2*t)/9+t*sympy.exp(t)/6
print("y:", autual_fun_sys1.subs(t, 3).evalf(17))

print("y\':", autual_fun_sys1.diff(t).subs(t, 3).evalf(17))


print("y\":", autual_fun_sys1.diff(t).diff(t).subs(t, 3).evalf(17))
