N=int(input())
dp=[1]*N
x=[*map(int,input().split())]
for i in range(1,N):
 for j in range(0,i):
  if x[j]>x[i]:
   dp[i]=max(dp[i],dp[j]+1)
print(max(dp))