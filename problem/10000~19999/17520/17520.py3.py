n=int(input())
mod=16769023
dp=[[0]*3 for i in range(n+1)]
dp[1][1]=dp[1][2]=1
for i in range(2,n+1):
 dp[i][0]=(dp[i-1][1]+dp[i-1][2])%mod
 dp[i][1]=dp[i-1][0]
 dp[i][2]=dp[i-1][0]
print(sum(dp[n])%mod)