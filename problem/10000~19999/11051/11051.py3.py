import math
f=math.factorial
a,b=map(int,input().split())
print(f(a)//f(b)//f(a-b)%10007)