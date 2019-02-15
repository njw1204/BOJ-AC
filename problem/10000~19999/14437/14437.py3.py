import math
F=math.factorial
C=lambda a,b:F(a)//F(b)//F(a-b)
H=lambda a,b:C(a+b-1,b)
s,n,a,i=int(input()),len(input()),0,0
while s>=i*26:
 a+=(1-i%2*2)*C(n,i)*H(n,s-i*26)
 i+=1
print(a%(10**9+7))