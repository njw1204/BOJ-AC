import math
f=math.factorial
w,h=map(int,input().split())
a,b=map(int,input().split())
print(f(a+b-2)//f(a-1)//f(b-1)*f(w+h-a-b)//f(w-a)//f(h-b)%1000007)