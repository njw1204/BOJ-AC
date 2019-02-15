from math import *
n,m=map(int,input().split())
aa,bb=11111,11111
for i in range(m):
  a,b=map(int,input().split())
  aa=min(a,aa)
  bb=min(b,bb)
ans=[ceil(n/6)*aa,n*bb,n//6*aa+n%6*bb]
print(min(ans))