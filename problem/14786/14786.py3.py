from math import *
a,b,c=map(int,input().split())
x=((c-b)/a+(c+b)/a)/2
for i in range(999999):
 t=x-(a*x+b*sin(x)-c)/(a+b*cos(x))
 if t==x: break
 x=t
print(x)