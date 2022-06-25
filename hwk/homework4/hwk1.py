# from http.client import PROCESSING
from sympy import symbols
import copy as cp
t, y = symbols('t y')

# expr = y-t*t+1


def comput_diff_par(fun, fun_par):
    res = fun.diff(t)+fun.diff(y)*fun_par
    return res


def euler_method(fun, a, b, alpha, N):
    h = (b-a)/N
    t_temp = a
    w_temp = alpha
    # print("{},{}".format(t_temp, w_temp))
    for i in range(1, N+1):
        w_temp = w_temp+h*fun.subs(t, t_temp).subs(y, w_temp)
        t_temp = a+i*h

    print(t_temp, w_temp)


# euler_method(expr, 0, 2, 0.5, 10)

def taylor_method(fun, a, b, alpha, N, degree):
    h = (b-a)/N
    t_temp = a
    w_temp = alpha
    fun_pal_n = [fun]
    for i in range(1, degree):
        fun_pal_temp = comput_diff_par(fun_pal_n[i-1], fun_pal_n[0])
        fun_pal_n.append(fun_pal_temp)

    T_N = fun
    par_temp = 1
    for i in range(1, degree):
        par_temp = h*par_temp/(i+1)
        T_N = T_N + par_temp*fun_pal_n[i]
    # print(T_N)
    for i in range(1, N+1):
        w_temp = w_temp + h*T_N.subs(t, t_temp).subs(y, w_temp)
        t_temp = a+i*h

    print(t_temp, w_temp)

# taylor_method(expr, 0, 2, 0.5, 10, 2)


def mid_point_method(fun, a, b, alpha, N):
    h = (b-a)/N
    t_temp = a
    w_temp = alpha

    for i in range(1, N+1):
        temp = h*fun.subs(t, t_temp).subs(y, w_temp)/2
        w_temp = w_temp+h*fun.subs(t, t_temp+h/2).subs(y, w_temp+temp)
        t_temp = a+i*h
        # print(t_temp, w_temp)

    print(t_temp, w_temp)


def modi_euler_method(fun, a, b, alpha, N):
    h = (b-a)/N
    t_temp = a
    w_temp = alpha

    for i in range(1, N+1):
        temp = fun.subs(t, t_temp).subs(y, w_temp)
        t_temp_p1 = a+i*h
        w_temp = w_temp+h * \
            (temp+fun.subs(t, t_temp_p1).subs(y, w_temp+h*temp))/2
        t_temp = t_temp_p1
        # print(t_temp, w_temp)

    print(t_temp, w_temp)


def heun_method(fun, a, b, alpha, N):
    h = (b-a)/N
    t_temp = a
    w_temp = alpha

    for i in range(1, N+1):
        temp = fun.subs(t, t_temp).subs(y, w_temp)
        w_temp = w_temp+(temp+3*fun.subs(t, t_temp+h*2 /
                                         3).subs(y, w_temp+2*h*temp/3))*h/4
        t_temp = a+i*h
        # print(t_temp, w_temp)

    print(t_temp, w_temp)


def runge_kutta_method_four(fun, a, b, alpha, N):
    h = (b-a)/N
    t_temp = a
    w_temp = alpha

    for i in range(1, N+1):
        K1 = h*fun.subs(t, t_temp).subs(y, w_temp)
        K2 = h*fun.subs(t, t_temp+h/2).subs(y, w_temp+K1/2)
        K3 = h*fun.subs(t, t_temp+h/2).subs(y, w_temp+K2/2)
        K4 = h*fun.subs(t, t_temp+h).subs(y, w_temp+K3)

        w_temp = w_temp+(K1+2*K2+2*K3+K4)/6
        t_temp = a+i*h
        # print(t_temp, w_temp)

    print(t_temp, w_temp)


def adams_bash_two(fun, a, b, w0, w1, N):
    h = (b-a)/N
    w = [w0, w1]
    t_temp = [a, a+h]

    for i in range(1, N):
        w_ip1 = w[i]+h*(3*fun.subs(t, t_temp[i]).subs(y, w[i]) -
                        fun.subs(t, t_temp[i-1]).subs(y, w[i-1]))/2
        w.append(w_ip1)
        t_temp.append(a+(i+1)*h)
    print(t_temp[N], w[N])


def adams_bash_three(fun, a, b, w0, w1, w2, N):
    h = (b-a)/N
    w = [w0, w1, w2]
    t_temp = [a, a+h, a+2*h]
    for i in range(2, N):
        w_ip1 = w[i]+h*(23*fun.subs(t, t_temp[i]).subs(y, w[i])
                        - 16*fun.subs(t, t_temp[i-1]).subs(y, w[i-1]) +
                        5*fun.subs(t, t_temp[i-2]).subs(y, w[i-2]))/12
        w.append(w_ip1)
        t_temp.append(a+(i+1)*h)

    print(t_temp[N], w[N])


def adams_bash_four(fun, a, b, w0, w1, w2, w3, N):
    h = (b-a)/N
    w = [w0, w1, w2, w3]
    t_temp = [a, a+h, a+2*h, a+3*h]

    for i in range(3, N):
        w_ip1 = w[i]+h*(55*fun.subs(t, t_temp[i]).subs(y, w[i])
                        - 59*fun.subs(t, t_temp[i-1]).subs(y, w[i-1])
                        + 37*fun.subs(t, t_temp[i-2]).subs(y, w[i-2])
                        - 9*fun.subs(t, t_temp[i-3]).subs(y, w[i-3]))/24
        w.append(w_ip1)
        t_temp.append(a+(i+1)*h)
    # print(w)
    print(t_temp[N], w[N])


def adams_bash_five(fun, a, b, w0, w1, w2, w3, w4, N):
    h = (b-a)/N
    w = [w0, w1, w2, w3, w4]
    t_temp = [a, a+h, a+2*h, a+3*h, a+4*h]

    for i in range(4, N):
        w_ip1 = w[i]+h*(1901*fun.subs(t, t_temp[i]).subs(y, w[i])
                        - 2774*fun.subs(t, t_temp[i-1]).subs(y, w[i-1])
                        + 2616*fun.subs(t, t_temp[i-2]).subs(y, w[i-2])
                        - 1274*fun.subs(t, t_temp[i-3]).subs(y, w[i-3])
                        + 251*fun.subs(t, t_temp[i-4]).subs(y, w[i-4]))/720
        w.append(w_ip1)
        t_temp.append(a+(i+1)*h)

    print(t_temp[N], w[N])


def adams_four_oder_pc(fun, a, b, alpha, N):
    h = (b-a)/N
    t_temp = [a]
    w_temp = [alpha]

    for i in range(1, 4):
        K1 = h*fun.subs(t, t_temp[i-1]).subs(y, w_temp[i-1])
        K2 = h*fun.subs(t, t_temp[i-1]+(h/2)).subs(y, w_temp[i-1]+(K1/2))
        K3 = h*fun.subs(t, t_temp[i-1]+(h/2)).subs(y, w_temp[i-1]+(K2/2))
        K4 = h*fun.subs(t, t_temp[i-1]+h).subs(y, w_temp[i-1]+K3)

        wi = w_temp[i-1]+(K1+2*K2+2*K3+K4)/6
        w_temp.append(wi)
        t_temp.append(a+i*h)

    for i in range(4, N+1):
        t_this = a+i*h
        w_this = w_temp[3]+h*(55*fun.subs(t, t_temp[3]).subs(y, w_temp[3])
                              - 59*fun.subs(t, t_temp[2]).subs(y, w_temp[2])
                              + 37*fun.subs(t, t_temp[1]).subs(y, w_temp[1])
                              - 9*fun.subs(t, t_temp[0]).subs(y, w_temp[0]))/24
        w = w_temp[3]+h*(9*fun.subs(t, t_this).subs(y, w_this)
                         + 19*fun.subs(t, t_temp[3]).subs(y, w_temp[3])
                         - 5*fun.subs(t, t_temp[2]).subs(y, w_temp[2])
                         + fun.subs(t, t_temp[1]).subs(y, w_temp[1]))/24

        for j in range(0, 3):
            t_temp[j] = t_temp[j+1]
            w_temp[j] = w_temp[j+1]
        w_temp[3] = w
        t_temp[3] = t_this

    print(t_temp[3], w_temp[3])


def runge_kutta_sys_diff_equ(a, b, fun: list, alpha: list, N):
    m = len(fun)
    h = (b-a)/N
    t_temp = a
    w_temp = []
    K1 = []
    K2 = []
    K3 = []
    K4 = []
    for i in range(0, m):
        w_temp.append(alpha[i])
        K1.append(0.0)
        K2.append(0.0)
        K3.append(0.0)
        K4.append(0.0)

    for i in range(0, N):

        for j in range(0, m):
            K1j = h*fun[j](t_temp, w_temp)
            K1[j] = K1j

        for j in range(0, m):
            k1temp = cp.deepcopy(K1)
            wtempthis = cp.deepcopy(w_temp)
            for k in range(0, m):
                wtempthis[k] = wtempthis[k]+k1temp[k]/2

            K2j = h*fun[j](t_temp+h/2, wtempthis)
            K2[j] = K2j
            # print("k2:", K2)
            # print(t_temp+h/2, wtempthis)

        for j in range(0, m):
            k2temp = cp.deepcopy(K2)
            wtempthis = cp.deepcopy(w_temp)
            for k in range(0, m):
                wtempthis[k] = wtempthis[k]+k2temp[k]/2

            k3j = h*fun[j](t_temp+h/2, wtempthis)
            K3[j] = k3j
            # print("k3:", K3)

        for j in range(0, m):
            k3temp = cp.deepcopy(K3)
            wtempthis = cp.deepcopy(w_temp)
            for k in range(0, m):
                wtempthis[k] = wtempthis[k]+k3temp[k]

            k4j = h*fun[j](t_temp+h, wtempthis)
            K4[j] = k4j
            # print("k4:", K4)

        for j in range(0, m):
            w_temp[j] = w_temp[j]+(K1[j]+2*K2[j]+2*K3[j]+K4[j])/6

        t_temp = t_temp+h
        # print(t_temp, w_temp)

    print(t_temp, w_temp)


print("asd")


def asdasd(x):
    return x
