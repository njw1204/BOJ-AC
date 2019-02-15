n=int(input())
x=[*map(int,input().split())]
dp=[9999]*n
dp[0]=0
for i in range(n):
 for j in range(i+1,i+x[i]+1):
  if j>=n: break
  dp[j]=min(dp[j],dp[i]+1)
if dp[n-1]==9999: print(-1)
else: print(dp[n-1])