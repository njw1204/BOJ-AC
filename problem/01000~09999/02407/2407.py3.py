from math import factorial
n,r=map(int,input().split())
print(factorial(n)//factorial(r)//factorial(n-r))