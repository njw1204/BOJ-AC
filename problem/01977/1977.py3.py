from math import *
M,N=int(input()),int(input())
result,min_num=0,0
for i in range(ceil(sqrt(M)),floor(sqrt(N))+1):
 result+=i*i
 if i==ceil(sqrt(M)): min_num=i*i
if min_num==0: print(-1)
else:
 print(result)
 print(min_num)