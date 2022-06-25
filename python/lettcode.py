'''
num1 twosum
'''
def twoSum(nums, target):
        for i in range(0,len(nums)):
            a=checkthenum(nums,i,target)
            if(a==len(nums)+10):
                i=i+1
            else:
                return [i,a]     
        return 0       

def checkthenum(nums:list,i:int=None,target:int=None):
        for j in range(i+1,len(nums)):
            if nums[i]+nums[j]==target:
                return j
            else:
                j=j+1
        return len(nums)+10
# nums=[2,3,11,15]
# target = 9
# print(twoSum(nums,target))

'''
num1 invert binary tree
'''

def revertlis(nums:list):
    a=[]
    for i in range(0,len(nums)):
        a.append(nums[len(nums)-i-1])
    return a

# xx=[1,2,3,4,5,6,7]
# print(revertlis(xx))

def checkthetr(nums:list):
    a=len(nums)-1
    # a=30
    b=0
    i=1
    while (a!=0):
        if(a%2==0):
            a=a-pow(2,i)
            i=i+1
        else:
            b=1
            break
    return b

# 0,1 1
# 1,3 
# 3,7
# print(checkthetr(xx))
# xx+[]
def revertree(nums:list):
    a=checkthetr(nums)
    if(a==1):
        return 1
    else:
        i=0
        j=0
        res=[]
        while (len(res)!=len(nums)):
            x=nums[i:i+pow(2,j)]
            x=revertlis(x)
            res+=x
            i=i+pow(2,j)
            j=j+1
        return res

# print(revertree(xx))

'''
num2 Longest Substring Without Repeating Characters
'''
# x="abceabcd"
# print(x[0])

def checkbac(x:str,i:int):
    a=set()
    b=""
    xx=x[i:len(x)]
    for i in range(0,len(xx)):
        if(xx[i] in a):
            return b
        else:
            a.add(xx[i])
            b=b+xx[i]
    return b

def largnumli(x:str):
    a=""
    for i in range(0,len(x)):
        if(len(checkbac(x, i))>len(a)):
            a=checkbac(x,i)
        else:
            True
    return a
# print(largnumli(x))

'''
num3 Add Two Numbers
'''

def revertlis(nums:list):
    a=[]
    for i in range(0,len(nums)):
        a.append(nums[len(nums)-i-1])
    return a

# x=[1,2,3,4]
# print(revertlis(x))

def addpre(x:list,y:list):
    for i in range(0,len(y)):
        x[len(x)-1-i]+=y[len(y)-i-1]
    return x

# y=[1,2,3]
# print(addpre(x,y))
def addtwonum(x:list,y:list):
    x=revertlis(x)
    y=revertlis(y)
    z=[]
    che=0
    if(len(x)>len(y)):
        True
    else:
        che=1
    if(che==0):
        return addpre(x,y)
    else:
        return addpre(y,x)

# print(addtwonum(y,x))

'''
num4  Median of Two Sorted Arrays
'''
# import numpy as np
# a=[1,2,3]
# b=[0,4,5]
def givemde(a:list,b:list):
    x=[]
    x=x+a+b
    x.sort()
    return np.median(x)

# print(givemde(a,b))

'''
num5 Longest Palindromic Substring
'''
# x="abba"

def ishuiwen(x:str):
    lenx=len(x)
    if (lenx%2==0):
        x1=x[0:lenx//2]
        x2=x[lenx//2:]
    else:
        x1=x[0:lenx//2]
        x2=x[lenx//2+1:]

    for i in range(0,lenx//2):
        if (x1[i]==x2[lenx//2-1-i]):
            True
        else:
            return False
    return True

# print(ishuiwen(x))

'''
num6  ZigZag Conversion
'''

# import numpy as np

def makestrmar(x:int,y:int):
    res=[]
    res1=[]
    for i in range(0,y):
        res1.append("")
    for i in range(0,x):
        res.append(res1.copy())
    return res



# print(makestrmar(2,2)[0][0])
def zigzag(x:str,n:int):
    thelic=n+n-2
    mod=len(x)//thelic
    # themart=np.zeros((n,mod+1)).tolist()
    add1=len(x)%thelic
    for i in range(0,n+n-1-add1):
        x+="1"
    themart=makestrmar(n,(n-1)*(mod+1))
    # print(mod,themart)
    for i in range(0,mod+1):
        for j in range(0,n):
            themart[j][i*(n-1)]=x[i*(thelic)+j]

        for k in range(0,n-1):
            themart[n-1-k][i*(n-1)+k]=x[i*(thelic)+n-1+k]
    return themart

def reslof5(x:str,n:int):
    thema=zigzag(x,n)
    zz=""
    thelic=n+n-2
    mod=len(x)//thelic
    for i in range(0,n):
        for j in range(0,(n-1)*(mod+1)):
            if thema[i][j]=="1":
                True
            else:
                zz+=thema[i][j]
        print(zz)
    return zz

# xyy="PAYPALISHIRING"

# print(reslof5(xyy,4))

'''
num7 Reverse Integer
'''
# x=123
def reverin(x:int):
    if x<0:
        x1= (-1)*x
    else:
        x1=x
    thelen=len(str(x1))
    resl=0
    for i in range(0,thelen):
        resl+=pow(10,thelen-1-i)*(x1%10)
        x1=int(x1/10)
    if x<0:
        resl= (-1)*resl
    else:
        resl=resl
    return resl
# print(reverin(-123))
'''
num8 String to Integer (atoi)
'''
# x="-42332w"
def reaad1(x:str):
    res=""
    thop=1
    thelis=list("0123456789")
    lenofx=len(x)
    operlis=["+","-"]
    for i in range(0,lenofx):
        if x[i] in thelis:
            res+=x[i]
        elif x[i] in operlis:
            if x[i]=="+":
              True
            else:
                thop=-1
        else:
            return thop*int(res)
    return thop*int(res)

# print(reaad1(x))

'''
num9 Palindrome Number

as same as num 5
'''

'''
num10  Regular Expression Matching
'''

import pandas as pd 
