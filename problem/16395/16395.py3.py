import math
f=math.factorial
a,b=map(int,input().split())
a-=1
b-=1
print(f(a)//f(b)//f(a-b))