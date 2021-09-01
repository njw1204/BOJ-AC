import math
n,m,kk=map(int,input().split())
a=0
for i in range(n+1):
 for j in range(m+1):
  for k in range(n+1):
   for l in range(m+1):
    if math.gcd(k-i,l-j)==kk-1: a+=1
print(a//2)