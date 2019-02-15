n,a=int(input()),0
while n>9:
 t,n=n,1
 while t:
  n*=t%10
  t//=10
 a+=1
print(a)