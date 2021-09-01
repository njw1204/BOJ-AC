N,K=map(int,input().split())
dp=[[[0]*3 for i in range(4)] for j in range(N+1)]
fix=[0]*(N+1)
for i in range(K):
  a,b=map(int,input().split())
  fix[a]=b

if fix[1]:
  dp[1][fix[1]][1]=1
else:
  dp[1][1][1]=dp[1][2][1]=dp[1][3][1]=1

for i in range(2,N+1):
  if fix[i]:
    for j in range(1,4):
      if j==fix[i]: continue
      dp[i][fix[i]][1]+=dp[i-1][j][1]+dp[i-1][j][2]
      dp[i][fix[i]][1]%=10000
    dp[i][fix[i]][2]=dp[i-1][fix[i]][1]
  else:
    for j in range(1,4):
      dp[i][j][2]=dp[i-1][j][1]
      for k in range(1,4):
        if j==k: continue
        dp[i][j][1]+=dp[i-1][k][1]+dp[i-1][k][2]
        dp[i][j][1]%=10000

print((dp[N][1][1]+dp[N][1][2]+dp[N][2][1]+dp[N][2][2]+dp[N][3][1]+dp[N][3][2])%10000)