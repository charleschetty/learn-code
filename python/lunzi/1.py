'''
注释是测试用的，像这种绿色字体写的是函数具体作用，以及一些问题
'''
import numpy as np
import fractions
import re    

np.set_printoptions(formatter={'all':lambda x: str(fractions.Fraction(x).limit_denominator())})
# A=np.array([[1/2,1],[1,1/2]])
# A1=np.array([[1/2,1,1],[1,1/2,1],[1,1,1/2]])
# B=np.array([[1,2],[3,4]])
# C=np.array([[1,2,3],[4,5,6],[7,8,9]])
# D=np.array([[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]])
# E=np.array([[2,1,1,1,1],[1,2,1,1,1],[1,1,2,1,1],[1,1,1,2,1],[1,1,1,1,2]])

def to_frac(a):
    lines = str(a).replace('/', '\n').splitlines()
    rv=[''.join(l.split())for l in lines]
    c=r"\frac{"+"{}".format(rv[0])+r"}{"+"{}".format(rv[1])+r"}"
    return c

# a='2/3'
# print(to_frac(a))
def re_frac(a):
    '''
    把3/2之类的表示成latex格式，\\frac{3}{2}
    '''
    pattern = re.compile(r'\d+\/[0-9]+') 
    x=pattern.findall(a)
    c=[]
    for i in x:
        c.append(str(to_frac(i)))
    for i in range(0,len(x)):
        a=a.replace(str(x[i]),to_frac(x[i]))
    return a

# a=r"""\begin{pmatrix}
#  -2 & 1\\
#   3/2 & -1/2\\"""
# print(re_frac(a))

def to_matrix(a,b='p'):
    '''
    把矩阵表示成latex
    '''
    c=""
    if b=="b":
        c="bmatrix"
    elif b=="p":
        c="pmatrix"
    lines = str(a).replace('[', '').replace(']', '').splitlines()
    #print(line for line in lines)
    rv = ["\\begin{%s}"%c]
    rv += ['  ' + ' & '.join(l.split()) + r'\\' for l in lines]
    rv +=  ['\\end{%s}'%c]
    return '\n'.join(rv)
# print(re_frac(to_matrix(B)))

def minor(mat, row=1, col=1):  
    '''
    计算余子式
    ''' 
    mat = np.delete(mat, row, axis=0)
    mat = np.delete(mat, col, axis=1)
    return mat

# print(C)
# print(minor(C,0,0))

def get_det(mat):  
    '''
    行列式数值，这里仅仅是2阶，其他的通过展开最后化成2阶的
    '''
    a=0
    if (mat.shape[0]==1):
        a=mat 
    elif(mat.shape[0]==2):
        a=mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0]
    else:
        for i in range(0,mat.shape[0]):
            a+=((-1)**(i))*mat[0][i]*(get_det(minor(mat,0,i)))
    return a

# print(get_det(A))
# print(get_det(C))

def minor_of_A(mat):  
    '''
    按照第一行展开
    '''
    b=[]
    c=[]
    for i in range(0,mat.shape[0]):
        b.append(minor(mat,0,i))
        c.append(((-1)**(i))*mat[0][i])
    return b,c

# print(C)
# x,y=minor_of_A(C)
# print(x)
# print(y)

def the_step_one(mat,c='no'):
    '''
    先按照第一行展开，不计算数值
    '''
    b,d=minor_of_A(mat)
    if c=='no':
        for i in range(0,mat.shape[0]-1):
            if((-1)**(i)==1):
                print("{0}*{1}".format(d[i],str(b[i])))
            else:
                print("{0}*{1}+".format(d[i],str(b[i])))
        print("{}*{}".format(d[mat.shape[0]-1],str(b[mat.shape[0]-1])))
    elif c=='tex':
        for i in range(0,mat.shape[0]-1):
            if((-1)**(i)==1):
                print("{0}\\times{1}".format(d[i],to_matrix(b[i],'b')))
            else:
                print("{0}\\times{1}+".format(d[i],to_matrix(b[i],'b')))
        print("{}*{}".format(d[mat.shape[0]-1],to_matrix(b[mat.shape[0]-1],'b')))
  
# print(C)
# print('\n')
# the_step_one(C)

def step_of_det(mat,d='no'):
    '''
    行列式一步一步求数值
    '''
    b,c=minor_of_A(mat)
    if d=='no':
        if(mat.shape[0]==2):
            print(get_det(mat))
        elif (mat.shape[0]==3):
            print("=")
            the_step_one(mat,'no')
            print("=")
            print(get_det(mat))
        else: #(mat.shape[0]==4):
            print("=")
            the_step_one(mat,'no')
            print('\n')
            b,c=minor_of_A(mat)
            for i in b:
                print(i)
                print("=")
                step_of_det(i,'no')
                print('\n')
    elif d=='tex':
        if(mat.shape[0]==2):
            print(get_det(mat))
        elif (mat.shape[0]==3):
            print("=")
            the_step_one(mat,'tex')
            print("=")
            print(get_det(mat))
        else:
            print("=")
            the_step_one(mat,'tex')
            print('\n')
            b,c=minor_of_A(mat)
            for i in b:
                print(i)
                print("=")
                step_of_det(i,'tex')
                print('\n')

def answer_of_det(mat,c='no'):
    if c=='tex':
        print(to_matrix(mat,'b'))
    step_of_det(mat,c)
    print("the answer is {}".format(get_det(mat)))

# answer_of_det(A1,'no')
# answer_of_det(A1,'tex')

def is_reversible(mat):
    '''
    是否可逆
    '''
    a=1
    if (get_det(mat)!=0):
        print("reversible")
        a=1
    else:
        print("not reversible")
        a=0
    return a

def adjoint_Matrix(mat):
    '''
    伴随矩阵
    '''
    b=mat.shape[0]
    a=np.random.rand(b,b)
    for i in  range(0,b):
        for j in  range(0,b):
            a[i][j]=get_det(minor(mat,j,i))*((-1)**(i+j))
    return a

# F=np.array([[1,0,0],[0,1,0],[0,0,1]])
# print(adjoint_Matrix(A1)) #F
# print(adjoint_Matrix(F))
def intervise_A(mat):
    '''
    逆矩阵
    '''
    a=is_reversible(mat)
    while (a):
        x=adjoint_Matrix(mat)/get_det(mat)
        print(x)
        a=0
    return x

def intervise_A_tex(mat):
    c=0
    print(r"A^{*}="+"{}".format(to_matrix(adjoint_Matrix(mat),'p'))+r"\\")
    print('det(A)={}'.format(get_det(mat))+r"\\")
    print(r"A^{-1}=\frac{1}{|A|}\times"+"{}".format(to_matrix(adjoint_Matrix(mat),'p'))+r"\\")
    a='={}'.format(to_matrix(adjoint_Matrix(mat)/get_det(mat),'p'))
    print(a)

def dot_tex(a,b):
    c=np.dot(a,b)
    print(c)

# dot_tex(B,B)
# intervise_A_tex(B)
# intervise_A(A1)
# print(A1.dot(intervise_A(A1)))
# a=r"""\begin{pmatrix}
#  -2 & 1\\
#   3/2 & -1/2\\"""
# print(re_frac(a))

def guass_i(A,p=1,k=0):
    x=A[p][k]
    Y=A[k][k]
    if Y==0:
        print("")
    else:
        for i in range(k,A.shape[0]+1):
            A[p][i]=A[p][i]+(x/A[k][k])*(-1)*A[k][i]
    return A

def exchange(A,i,j):
    B=A[i].copy()
    A[i]=A[j]
    A[j]=B
    return A

def print_guass(A,xx=0):
    '''
    高斯消去法，设置参数是否输出tex
    '''
    for k in range(0,A.shape[0]):
        if A[k][k]==0:
            c=0
            for i in range(k,A.shape[0]):
                if A[i][k]!=0:
                   c=i
                   break
            if (c==0):
                print("")
            else:
                exchange(A,c,k)
        else:
            for i in range(0,A.shape[0]):
                if(i==k):
                    print("")
                else:
                    A=guass_i(A,i,k)
                    if (xx==0):
                        print(A)
                    else:
                        print(to_matrix(A))


# B_guass=np.array([[1,2,3,11,55],[0,5,6,11,56],[7,8,9,11,57],[22,23,24,25,58]])
# A_guass=np.array([[1,2,3,11,55],[4,5,6,11,56],[7,8,9,11,57],[22,23,24,25,58]])
# print_guass(A_guass,0)

class Rational1:
    '''
    有理数类
    '''
    @staticmethod
    def gcd(m,n):
        if n==0:
            m,n=n,m
        while m!=0:
            m,n=n%m,m
        return n
    
    def __init__(self,num,den=1):
        if not isinstance(num,int) or not isinstance(den,int):
            raise TypeError
        if den==0:
            raise ZeroDivisionError
        sign=1
        if num<0:
            num,sign=(-1)*num,(-1)*sign
        if den<0:
            den,sign=(-1)*den,(-1)*sign
        g=Rational1.gcd(num,den)
        self.num=sign*(num//g)
        self.den=den//g

    def to_int(self):
        if self.den==1:
            a=self.num 
        else:
            a=self
        return a

    def to_zero(self):
        if (self.den==1)&(self.num==0):
            a=self.num 
        else:
            a=self
        return a

    def get_den(self):
        return self.den

    def get_num(self):
        return self.num

    def __add__(self,another):
        if isinstance(another, int):
            another=Rational1(another,1)
        den=self.den*another.get_den()
        num=(self.num*another.get_den())+(self.den*another.get_num())
        return Rational1(num,den)
    
    def __sub__(self,another):
        if isinstance(another, int):
            another=Rational1(another,1)
        den=self.den*another.get_den()
        num=(self.num*another.get_den())-(self.den*another.get_num())
        return Rational1(num,den)

    def __mul__(self,another):
        if isinstance(another, int):
            another=Rational1(another,1)
        elif isinstance(self,int):
            self=Rational1(self,1)
        return Rational1(self.num*another.get_num(),self.den*another.get_den())
    
    def __floordiv__(self, another):
        if another.get_num()==0:
            raise ZeroDivisionError
        return Rational1(self.num*another.get_den(),self.den*another.get_num())
    
    def __eq__(self,another):
        if another==0:
            a= (0==self.num) 
        # elif another==Rational1(0,1)
        elif isinstance(another,int):
            another=Rational1(another,1)
            a=self.num*another.get_den()==self.den*another.get_num()
        return a

    def __it__(self,another):
        return self.num*another.get_den()<self.den*another.get_num()

    def __gt__(self, another):
        return self.num*another.get_den()>self.den*another.get_num()

    def __str__(self):
        return str(self.num)+"/"+str(self.den)

    
# a=Rational1(3,2)
# b=Rational1(4,5)
# c=Rational1(3,1)
# d=Rational1(0,1)
# print(c.to_zero())
# print(d.to_zero())
# print(c.to_int())
# print(b.to_int())

class dxs:
    '''
    多项式类
    '''
    def __init__(self,degree=[0,1,2,3,4,5],pam=[0,0,0,0,0,0]) -> None:
        a=len(degree)-len(pam)
        if a==0:
            self.degree=degree
            self.pam=pam
        elif a<0:
            raise TypeError
        elif a>0:
            for i in range(0,a):
                # degree.pop()
                pam.append(0)
            self.degree=degree
            self.pam=pam
    def clear(self):
        y=0
        for i in range(0,len(self.pam)):
            if self.pam[i]!=0:
                y=i
        for i in range(0,len(self.pam)-y-1):
            self.pam.pop()
            self.degree.pop()
        return self
    
    def get_max(self):
        '''
        求最高项次数
        '''
        a=0
        for i in range(0,len(self.degree)):
            if self.pam[i]!=0:
                a=i
        return self.degree[a]

    def to_Rational1(self):
        '''
        这三个要做的是把两个多项式弄成一样长度，不能加clear，否则这三个就根没有一样，
        same也是一样，作的仅仅对于数据结构进行变换让他好处理，一个clear就又变回来了
        '''
        y=[]
        for i in range(0,len(self.pam)):
            if  isinstance(self.pam_show()[i],int) :
                y.append(Rational1(self.pam_show()[i],1))
            elif isinstance(self.pam_show()[i],Rational1):
                y.append(self.pam_show()[i])
        a=dxs(self.degree_show(),y)
        return a
    
    def to_int_dxs(self):
        y=[]
        for i in range(0,len(self.pam)):
            if isinstance(self.pam_show()[i],Rational1):
                y.append(self.pam_show()[i].to_int())
            elif isinstance(self.pam_show()[i],int):
                y.append(self.pam_show()[i])
        a=dxs(self.degree_show(),y)
        return a

    def to_zero_dxs(self):
        y=[]
        for i in range(0,len(self.pam)):
            y.append(self.pam_show()[i].to_zero())
        a=dxs(self.degree_show(),y)
        return a

    def same(self,b):
        '''
        把两个多项式化作同样表示，例如一个是[0,1,2,3],[1,1,1,1]，一个是[0,1],【1,1]
        化作[0,1,2,3],[1,1,0,0]
        '''
        self_pam=self.pam_show()
        self_degree=self.degree_show()
        pam=b.pam_show()
        degree=b.degree_show()

        max_degree=degree[len(degree)-1]
        max_degree_of_self=self_degree[len(self_degree)-1]
        if max_degree>max_degree_of_self:
            a=max_degree-max_degree_of_self
            for i in range(0,a):
                self_pam.append(0)
                self_degree.append(max_degree_of_self+i+1)
        elif max_degree<max_degree_of_self:
            a=max_degree_of_self-max_degree
            for i in range(0,a):
                pam.append(0)
                degree.append(max_degree+i+1)
        return dxs(self_degree,self_pam) ,dxs(degree,pam)
    
    def __str__(self):
        a=self.degree  
        b=self.pam
        x=""
        p=0 
        for i in range(0,len(a)):
            if b[i]!=0:
                p=i
        for i in range(0,p):
            if b[i]==0:
                s=1
            else:
                if i==0:
                    x=x+str(b[0])+"+"
                else:
                    x=x+str(b[i])+r"x^"+str(a[i])+"+"
        if b[p]==0:
            s=1
        else:
            x=x+str(b[p])+r"x^"+str(a[p])
        return x

    def pam_show(self):
        '''
        这看起来是多此一举，那不妨直接替换成return self.pam，
        然后我们随便取a,b,让c,d=a.same(b),然后看一下a,b是否改变
        python最蛋疼的地方就在于没有指针，但是实际上这就是个指针，所以不想用的时候十分麻烦，
        而且bug十分隐蔽，所以我通篇用pam_show,degree_show，这个bug整了老半天,下面copy同样
        '''
        y=[]
        for i in range(0,len(self.pam)):
            y.append(self.pam[i])
        return y
    
    def degree_show(self):
        y=[]
        for i in range(0,len(self.degree)):
            y.append(self.degree[i])
        return y
    
    def copy(self):
        return dxs(self.degree_show(),self.pam_show())

    def show_self(self):
        print("degree:")
        print(self.degree_show())
        print("pam:")
        print(self.pam_show())
        
    def __add__(self,b):
        x,y=self.same(b)
        x=x.to_Rational1()
        y=y.to_Rational1()
        c=[]
        for i in range(0,len(x.degree_show())):
            c.append(y.pam_show()[i]+x.pam_show()[i])
        return dxs(x.degree_show(),c).to_int_dxs().clear()

    def __sub__(self, b):
        x,y=self.same(b)
        x=x.to_Rational1()
        y=y.to_Rational1()
        c=[]
        for i in range(0,len(x.degree_show())):
            c.append(x.pam_show()[i]-y.pam_show()[i])
        return dxs(x.degree_show(),c).to_int_dxs().clear()

    def mul_step_one(self,deg,pam):
        '''
        给出单一多项式，例如3x^2,那么就是deg=2,pam=3
        '''
        a=self.to_Rational1()
        degree_max=a.get_max()+deg 
        degree=[]
        pam_lis=[]
        for i in range(0,degree_max+1):
            degree.append(i)
            pam_lis.append(0)
        for i in range(deg,degree_max+1):
            pam_lis[i]=a.pam_show()[i-deg]*pam
        return dxs(degree,pam_lis).to_int_dxs().clear()

    def __mul__(self, b):
        a,b_1=self.same(b)
        degree=b_1.degree_show()
        pam=b_1.pam_show()
        x_pam=[]
        x_degree=[]
        for i in range(0,len(degree)):
            x_pam.append(0)
            x_degree.append(i)
        y=dxs(x_degree,x_pam)
        for i in range(0,len(x_pam)):
            t=a.mul_step_one(degree[i],pam[i])
            # y,t=y.same(t)
            y=y+t
        return y.clear()
    
    def floordiv_step_one(self,b):
        deg=self.get_max()-b.get_max()
        a,b_1=self.same(b)
        a=a.to_Rational1().to_zero_dxs()
        b_1=b_1.to_Rational1().to_zero_dxs()
        pam_pre=a.pam_show()[a.get_max()]//b_1.pam_show()[b_1.get_max()]
        degree=[]
        pam=[]
        for i in range(0,deg+1):
            degree.append(i)
            pam.append(0)
        pam[deg]=pam_pre
        return dxs(degree,pam).clear()

    def __floordiv__(self, b):
        deg=self.get_max()-b.get_max()
        if deg>0:
            x_1=self.floordiv_step_one(b)
        else:
            raise ZeroDivisionError
        return x_1.clear()
    
    def __mod__(self, b):
        deg=self.get_max()-b.get_max()
        c=b.to_Rational1().to_zero_dxs()
        d=self.to_Rational1().to_zero_dxs()
        if deg>0:
            x_1=self.floordiv_step_one(b)
            x_2=d-(x_1*c)
        else:
            raise ZeroDivisionError
        return x_2.clear()

    def __eq__(self,b):
        if b==0:
            x=0
            y=0
            for i in range(0,len(self.pam)):
                if self.pam[i]==0:
                    x=0
                else:
                    y=1
            a=(y==0)
        # elif another==Rational1(0,1)
        else:
            x=0
            y=0
            a,b_1=self.same(b)
            for i in range(0,len(a.pam_show())):
                if a.pam_show()[i]==b_1.pam_show()[i]:
                    x=0
                else:
                    y=1
            a=(y==0)
        return a

# a=dxs([0,1,2,3,4,5],[0,1,1,1,1,0])
# b=dxs([0,1,2,3,4],[2,2,2,2,9])
d=dxs([0,1,2,3],[0,3,0,2])
# print(d)
# print(d.degree_show())
# print(d.pam_show())
zz=dxs([0,1,2],[2,3,4])
# pp=dxs([0,1,2,3,4,5,6],[1,2])
# print(pp.clear().show_self())
# print(a)
# x=a.mul_step_one(5,33)
# print(x)
# print(a.get_max())
# c=a*b
# print(c.show_self())
# print(a.show_self())
# print(b.show_self())
# print(c)
# print(d)
# d=d.to_Rational1()
# print(d)
# d=d.to_int_dxs()
# print(d)
# print(zz)
# yy=d.floordiv_step_one(zz)
# print(yy)
# print(d.to_Rational1())
# print(d.to_Rational1().to_zero_dxs())
# print(d)
# print(zz)
# sss=d//zz
# print(sss)
# ss=d%zz
# print(ss)
# print(d==zz)
# print(zz==d)
# wwww=dxs([0,1,2,3,4],[0,0,0,0,0])
# print(wwww==0)

def poly_to_tex(a):
    a=str(a)
    a=a.replace("^",r"^{").replace("+",r'}+')+"}"
    a=re_frac(a)
    return a

# print(poly_to_tex('3/2x^1+2x^3'))

def division_pre(m,n):
    if n==m:
        x=m
        y=0
    elif m.get_max()>n.get_max():
        x=m//n
        y=m%n
    elif m.get_max()<n.get_max():
        x,y=division_pre(n,m)
    return x,y

def division(m,n):
    m_deg=m.get_max()
    n_deg=n.get_max()
    if m_deg>n_deg:
        a,b=division_pre(m,n)
        x=str(m)+"="+str(a)+"*("+str(n)+")"+"+"+str(b)
    elif n_deg==m_deg:
        x="the max degree is same"
    else:
        a,b=division_pre(m,n)
        x=str(n)+"="+str(a)+"*("+str(m)+")"+"+"+str(b)
    print(x)
# d,z=d.same(zz)
# print(d.show_self())
# print(zz.show_self())
# print(d)
# print(zz)
# division(d,zz)
# x,y=division_pre(zz,d)

def gcd_dxs(m,n):
    a=m.copy()
    b=n.copy()
    a_deg=a.get_max()
    b_deg=b.get_max()
    if a_deg==b_deg:
        division(a,b)
    else:
        while (a.get_max()!=b.get_max()):
            division(a,b)
            if a_deg>b_deg:
                x,y=division_pre(a,b)
                a,b=b,y
            elif a_deg<b_deg:
                x,y=division_pre(a,b)
                a,b=a,y
            gcd_dxs(a,b)

hhhh=dxs([0,1,2],[0,1,0])
hh=dxs([0,1,2],[0,0,1])
gcd_dxs(zz,d)


