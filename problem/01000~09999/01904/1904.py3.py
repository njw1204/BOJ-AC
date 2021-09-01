n=int(input())
dp=[[0]*2 for i in range(n+1)]
dp[1][1]=1
dp[2][0]=1
dp[2][1]=1
for i in range(3,n+1):
    dp[i][0]=(dp[i-2][0]+dp[i-2][1])%15746
    dp[i][1]=(dp[i-1][0]+dp[i-1][1])%15746
print((dp[n][0]+dp[n][1])%15746)