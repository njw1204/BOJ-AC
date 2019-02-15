n=int(input())
cost=[0]*n
for i in range(n):
 cost[i]=[*map(int,input().split())]
dp=[[cost[0][0],cost[0][1],cost[0][2]] for i in range(n)]
for i in range(1,n):
 dp[i][0]=min(dp[i-1][1],dp[i-1][2])+cost[i][0]
 dp[i][1]=min(dp[i-1][0],dp[i-1][2])+cost[i][1]
 dp[i][2]=min(dp[i-1][0],dp[i-1][1])+cost[i][2]
print(min(dp[n-1]))