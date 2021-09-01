n=int(input())
x=[0]*(n+1)
dp=[0]*(n+1)
for i in range(1,n+1):
 x[i]=[*map(int,input().split())]
 if i+x[i][0]<=n+1: dp[i]=x[i][1]
for i in range(1,n+1):
 for j in range(1,i):
  if j+x[j][0]<=i:
   if i+x[i][0]<=n+1: dp[i]=max(dp[i],dp[j]+x[i][1])
   else: dp[i]=max(dp[i],dp[j])
print(max(dp))