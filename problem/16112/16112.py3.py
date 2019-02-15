m=lambda:map(int,input().split())
n,k=m()
x,a=sorted(m()),0
for i in range(n): a+=min(i,k)*x[i]
print(a)