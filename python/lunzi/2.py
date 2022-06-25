from sympy import *
import numpy as np
import itertools

x,y=symbols('x,y')
init_printing(use_unicode=True)


mar=Matrix([[x,-1,1],[1,x,-1],[1,1,-1]])
#print(mar.det())
#print(shape(mar)[0])
# a_x=mar.row(0).col(0)
#print(a_x.det())


def D_select_pre(x:Matrix,col=0,n=[0]):
    a=[]
    for i in range(0,len(n)):
        a.append(x.row(col).col(n[i]).det())
    return a
#aaaa=[0,1]
#print(D_select_pre(mar,0,aaaa))

def n_select_m(n,m):
    a_n=[]
    for i in range(0,n):
        a_n.append(i)
    a=list(itertools.combinations(a_n,m))
    return a
#print(n_select_m(3,2))

def D_x_select(x:Matrix,m=(0,1),n=(0,1)):
    m=list(m)
    n=list(n)
    the_list=[]
    for i in range(0,len(m)):
        the_list.append(D_select_pre(x,m[i],n))
    return Matrix(the_list)

#print(D_x_select(mar))
    
def D_x_pre(x:Matrix,num=1):
    b=[]
    a=n_select_m(shape(mar)[0],num)
    num_select=n_select_m(len(a),2)
    for i in range(0,len(num_select)):
        for j in range(0,len(num_select)):
            b.append(D_x_select(x,a[i],a[j]).det())
    return b

#print(D_x_pre(mar,2))    
def zero_replace(a:list):
    zz=[]
    for i in range(0,len(a)):
        if a[i]==0:
            hh=1
        else:
            zz.append(a[i])
    return zz

#use=zero_replace(D_x_pre(mar,1))

#print(gcd_list(use))


def D_X(x:Matrix):
    aa=[]
    for i in range(1,shape(x)[0]):
        a=zero_replace(D_x_pre(x,i))
        aa.append(gcd_list(a))
    aa.append(x.det())
    return aa

#print(D_X(mar))


asd=Matrix([[1,1,1],[1,1,1],[1,1,1]])

def d_x(x:Matrix):
    zz=D_X(x)
    a=[zz[0]]
    for i in range(1,len(zz)):
        a.append(cancel(zz[i]/zz[i-1]))
    return a
#print(D_X(asd))
#print(d_x(mar))

def jordan_kuai_pre(x_1=0,x_2=1,num_1=2,num_2=2,degree=3):
    a=[]
    for i in range(0,degree):
        if i==x_1:
            a.append(num_1)
        elif i==x_2:
            a.append(num_2)
        else:
            a.append(0)
    return a

#print(jordan_kuai_pre(0,1,3,4,5))
def jordan_kuai(num=1,deg=2):
    if deg==1:
        ahah=Matrix([num])
    else:
        a=[]
        for i in range(0,deg-1):
            a.append(jordan_kuai_pre(x_1=i,x_2=i+1,num_1=num,num_2=1,degree=deg))
        a.append(jordan_kuai_pre(x_1=deg-1,x_2=1,num_1=num,num_2=0,degree=deg))
        ahah=Matrix(a)
    return ahah

def lamda_biaozhun(x,tex=0):
    a=D_X(x)
    b=d_x(x)
    for i in range(0,len(a)):
        print("D_{} is ".format(i)+str(a[i]))
    for i in range(0,len(a)):
        print("d_{} is ".format(i)+str(b[i]))
    print("so ,is")
    if  not tex:
        print(Matrix(diag_from_list(b)))
    elif tex:
        print(latex(Matrix(diag_from_list(b))))
def diag_from_list(x:list):
    a=[]
    for i in range(0,len(x)):
        hh=[]
        for j in range(0,len(x)):
            if i==j:
                hh.append(x[j])
            else:
                hh.append(0)
        a.append(hh)
    return a


# print(jordan_kuai(3,5))
#print(latex(mar))
#print(diag_from_list(d_x(mar)))
#print(Matrix(diag_from_list(d_x(mar))))

#lamda_biaozhun(mar,0)

def lamda_I_sub_A(mar:Matrix):
    lamda = symbols('lamda')
    a=[]
    for i in range(0,shape(mar)[0]):
        zz=[]
        for j in range(0,shape(mar)[0]):
            if i==j:
                zz.append(lamda+(-1)*mar.row(i).col(j).det())
            else:
                zz.append((-1)*mar.row(i).col(j).det())
        a.append(zz)
    return Matrix(a)
asd=Matrix([[1,1,1],[1,1,1],[1,1,1]])
#print(lamda_I_sub_A(asd).det())
def x_I_sub_A(mar:Matrix):
    x = symbols('x')
    a=[]
    for i in range(0,shape(mar)[0]):
        zz=[]
        for j in range(0,shape(mar)[0]):
            if i==j:
                zz.append(x+(-1)*mar.row(i).col(j).det())
            else:
                zz.append((-1)*mar.row(i).col(j).det())
        a.append(zz)
    return Matrix(a)
#ahjj=x_I_sub_A(asd)
#print(ahjj)
def jordan_print(mar:Matrix,tex=0):
    lamda_mar=x_I_sub_A(mar)
    a=d_x(lamda_mar)
    print("d_X =")
    if tex:
        print(latex(a))
    else:
        print(a)
    #print(a)
    b=[]
    for i in range(0,len(a)):
        if a[i]==1:
            c=0
        else:
            b.append(a[i])
    #print(b)
    jordan_list=[]
    for i in range(0,len(b)):
        jordan_list.append(roots(b[i],x))
    #print(jordan_list)
    jordan_kuai_lis=[]
    for i in range(0,len(jordan_list)):
        zz=[]
        key_1=[]
        key_2=[]
        for key in jordan_list[i]:
            key_1.append(key)
            key_2.append(jordan_list[i][key])
        for k in range(0,len(key_1)):
            jordan_kuai_lis.append([key_1[k],key_2[k]])
    # print(jordan_kuai_lis)  
    print("the primary factor is")
    for i in range(0,len(jordan_kuai_lis)):

        print(r"(x-"+str(jordan_kuai_lis[i][0])+r")^"+str(jordan_kuai_lis[i][1]))
    jordan_kuai_mar=[]
    for i in range(0,len(jordan_kuai_lis)):
        jordan_kuai_mar.append(jordan_kuai(jordan_kuai_lis[i][0],jordan_kuai_lis[i][1]))
    # print(jordan_kuai_mar)
    print("the jordan lump is")
    for i in range(0,len(jordan_kuai_mar)):
        if tex:
            print(latex(jordan_kuai_mar[i]))
        else:
            print(jordan_kuai_mar[i])
    jordan_B=diag(jordan_kuai_mar,unpack=True)
    print("the jordan normalized form is")
    if tex:
        print(latex(jordan_B))
    else:
        print(jordan_B)
#jordan_print(asd,1)

def lamda_x_solve(mar:Matrix,num):
    a=[]
    for i in range(0,shape(mar)[0]):
        zz=[]
        for j in range(0,shape(mar)[0]):
            if i==j :
                zz.append(num-mar.col(i).row(j).det())
            else:
                zz.append((-1)*mar.row(i).col(j).det())
        a.append(zz)
    ahhh=[]
    a_Matrix=Matrix(a)
    for i in range(0,shape(mar)[0]):
        ahhh.append(0)
    ahhh_Martix=Matrix(ahhh)
    solve,params=a_Matrix.gauss_jordan_solve(ahhh_Martix)
    dict_1=[]
    for i in range(0,shape(params)[0]):
        dict_2={}
        for j in range(0,shape(params)[0]):
            if i==j:
                dict_2[params[j]]=1
            else:
                dict_2[params[j]]=0
        dict_1.append(dict_2)
    feature_vector=[]
    for i in range(0,len(dict_1)):
        feature_vector.append(solve.xreplace(dict_1[i]))
    return feature_vector
#print(lamda_x_solve(asd,0))
#print(lamda_x_solve(asd,3))

def res_show(a:list,tex=0):
    for i in range(0,len(a)):
        if tex:
            print(latex(a[i]))
        else:
            print(a[i])

def row_make(num,x_1,degree):
    a=[]
    for i in range(0,degree):
        if i==x_1:
            a.append(num)
        else:
            a.append(0)
    return a

#print(row_make(3,2,5))

def similar_print(mar:Matrix, tex=0):
    zz=lamda_I_sub_A(mar)
    print(r"lamda I -A=")
    if tex:
        print(latex(zz))
    elif not tex:
        print(zz)
    print(r"det of lamda I -A is")
    print(factor(zz.det()))
    result=solve(zz.det())
    #print(result)
    print("the result is ")
    str_res=""
    for i in range(0,len(result)):
        str_res=str_res+str(result[i])+","
    print(str_res)
    print("the feature vector is :")
    feature_vector=[]
    for i in range(0,len(result)):
        for j in range(0,len(lamda_x_solve(mar,result[i]))):
            feature_vector.append(lamda_x_solve(mar,result[i])[j])
        res_show(lamda_x_solve(mar,result[i]),tex)
    #print(feature_vector)
    p=[]
    for i in range(0,shape(mar)[0]):
        zz=[]
        for j in range(0,shape(mar)[0]):
            zz.append(0)
        p.append(zz)
    for i in range(0,len(p)):
        for j in range(0, len(p)):
            p[i][j]=feature_vector[j].row(i).det()
    sim_p=Matrix(p)
    B_num=[]
    for i in range(0,len(result)):
        B_num.append(len(lamda_x_solve(mar,result[i])))
    #print(B_num)
    B_lis=[]
    for i in range(0,len(feature_vector)):
        zz=[]
        for j in range(0,len(feature_vector)):
            zz.append(0)
        B_lis.append(zz)
    shit=0
    for i in range(0,len(result)):
        for j in range(0,B_num[i]):
            B_lis[shit][shit]=result[i]
            shit=shit+1
    #print(B_lis)
    sim_b=Matrix(B_lis)
    print("P=")
    if tex:
        print(latex(sim_p))
    else:
        print(sim_p)
    print("B=")
    if tex:
        print(latex(sim_b))
    else:
        print(sim_b)
similar_print(asd,0)

def inner_eucild(m:list,n:list) :
    zz=0
    for i in range(0,len(m)):
        zz=zz+m[i]*n[i]
    return zz

# aasssss=[0,1,1,1]
# sggsgs=[1,0,1,1]
# print(inner_eucild(aasssss,sggsgs))
def sim_ortho(a:list):
    res=[a[0]]
    for i in range(1,len(a)):
        zz=[]
        for j in range(0,i):
            rai_1=Rational(inner_eucild(a[i],res[j]),inner_eucild(res[j],res[j]))
            # print(rai_1)
            zz_i=[]
            for k in range(0,len(res[j])):
                zz_i.append(rai_1*res[j][k])
            zz.append(zz_i)
        # print(zz)
        simi_pre=[]
        # print(zz)
        for p in range(0,len(zz[0])):
            hh=0
            for j in range(0,len(zz)):
                hh+=zz[j][p]
            simi_pre.append(hh)
        # print(simi_pre)
        simi_i=[]
        # print(simi_pre)
        for k in range(0,len(simi_pre)):
            shit=a[i][k]-simi_pre[k]
            simi_i.append(shit)
        res.append(simi_i)
        # print(simi_i)
    return res

def sim_ortho_standard(a:list):
    simi=[]
    for i in range(0,len(a)):
        zz=[]
        fck=sqrt(inner_eucild(a[i],a[i]))
        # print(fck)
        for k in range(0,len(a[i])):
            zz.append(a[i][k]/fck)
        simi.append(zz)
    return simi

the_fcu=[[1,1,0,0],[1,0,1,0],[-1,0,0,1],[1,-1,-1,1]]
print(sim_ortho(the_fcu))
print(sim_ortho_standard(sim_ortho(the_fcu)))




