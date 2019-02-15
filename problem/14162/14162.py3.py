import math
l,r=map(int,input().split())
a=0
for i in range(1,r+1): a+=(r//i-math.ceil(l/i)+1)*i
print(a)