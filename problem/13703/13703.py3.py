k,n=map(int,input().split())
dp=[[0]*205 for i in range(205)]
dp[0][k]=1
for i in range(1,n+1):
  for j in range(1,200):
    dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1]
print(sum(dp[n]) if k else 0)