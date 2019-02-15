while 1:
 n=int(input())
 if n==0: break
 dp=[[0]*(n+2) for _ in range(n+2)]
 dp[n][0]=1
 for x in range(n-1,-1,-1):
  for y in range(n,-1,-1):
   dp[x][y]=dp[x+1][y-1]+dp[x][y+1]
 print(dp[0][0])