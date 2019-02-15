n=int(input())
x=[*map(int,input().split())]
dp1,dp2=[1]*n,[1]*n
for i in range(1,n):
 for j in range(i):
  if dp1[j]+1>dp1[i] and x[j]<x[i]:
   dp1[i]=dp1[j]+1
for i in range(n-2,-1,-1):
 for j in range(n-1,i,-1):
  if dp2[j]+1>dp2[i] and x[j]<x[i]:
   dp2[i]=dp2[j]+1
ans=1
for i in range(n):
 ans=max(ans,dp1[i]+dp2[i]-1)
print(ans)