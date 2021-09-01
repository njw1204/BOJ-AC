n,a=int(input()),0
for i in range(2,n//2+1):a+=(n//i-1)*i
print(a%10**6)