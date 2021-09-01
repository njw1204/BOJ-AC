from math import *
f=factorial

def comb(n,r):
    return f(n)//f(r)//f(n-r)

def hcomb(n,r):
    return comb(n+r-1,r)

n=int(input())
m=int(input())-n
print(hcomb(n,m))