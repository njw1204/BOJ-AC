n,m=map(int,input().split())
x,dp=[],[[0]*(m+1) for _ in range(n+1)]
for i in range(n): x.append([*map(int,input().split())])
for i in range(n-1,-1,-1):
 for j in range(m-1,-1,-1):
  dp[i][j]=max(dp[i+1][j],dp[i][j+1])+x[i][j]
print(dp[0][0])