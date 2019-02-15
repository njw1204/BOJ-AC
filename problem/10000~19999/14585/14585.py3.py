field=[[0]*301 for i in range(301)]
dp=[[0]*301 for i in range(301)]
n,m=map(int,input().split())
for i in range(n):
  a,b=map(int,input().split())
  field[a][b]=m

ans=0
if field[0][0]:
  dp[0][0]=field[0][0]
  ans=dp[0][0]

for i in range(301):
  for j in range(301):
    if i+j==0: continue
    k=field[i][j]-i-j
    if i==0:
      dp[i][j]=dp[i][j-1]
      if k>0: dp[i][j]+=k
    elif j==0:
      dp[i][j]=dp[i-1][j]
      if k>0: dp[i][j]+=k
    else:
      dp[i][j]=max(dp[i-1][j],dp[i][j-1])
      if k>0: dp[i][j]+=k
    ans=max(ans,dp[i][j])

print(ans)