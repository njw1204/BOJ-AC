import math
f=math.factorial
n,k=map(int,input().split())
print(f(n)//f(k)//f(n-k))