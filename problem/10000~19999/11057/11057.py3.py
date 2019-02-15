import math
f=math.factorial
n=int(input())
print(f(n+9)//f(n)//f(9)%10007)