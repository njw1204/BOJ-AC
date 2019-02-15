n,m=map(int,input().split())
dp=[[0]*(m+1) for i in range(n+1)]
dp[n][m]=1
for i in range(n,0,-1):
 for j in range(m,0,-1):
  if i<n: dp[i][j]+=dp[i+1][j]
  if j<m: dp[i][j]+=dp[i][j+1]
  if i<n and j<m: dp[i][j]+=dp[i+1][j+1]
  dp[i][j]%=1000000007
print(dp[1][1])