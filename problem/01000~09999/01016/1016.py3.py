from math import *
left,right=map(int,input().split())
x=[True]*(right-left+1)
for i in range(2,int(sqrt(right))+1):
 j=i*i
 while j<=right:
  if j<left:
   j*=ceil(left/j)
   continue
  x[j-left]=False
  j+=i*i
print(sum(x))