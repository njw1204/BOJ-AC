n=int(input())
cost=[0]*n
for i in range(n):
    cost[i]=[*map(int,input().split())]

dp=[[[10**18]*3 for j in range(6)] for i in range(n)]
dp[0][0][0]=cost[0][0]+cost[n-1][1]
dp[0][1][0]=cost[0][0]+cost[n-1][2]
dp[0][2][1]=cost[0][1]+cost[n-1][0]
dp[0][3][1]=cost[0][1]+cost[n-1][2]
dp[0][4][2]=cost[0][2]+cost[n-1][0]
dp[0][5][2]=cost[0][2]+cost[n-1][1]

for i in range(1,n-1):
    for j in range(6):
        dp[i][j][0]=min(dp[i-1][j][1],dp[i-1][j][2])+cost[i][0]
        dp[i][j][1]=min(dp[i-1][j][0],dp[i-1][j][2])+cost[i][1]
        dp[i][j][2]=min(dp[i-1][j][0],dp[i-1][j][1])+cost[i][2]

        if i==n-2:
            if j==0:
                dp[i][j][1]=10**18
            if j==1:
                dp[i][j][2]=10**18
            if j==2:
                dp[i][j][0]=10**18
            if j==3:
                dp[i][j][2]=10**18
            if j==4:
                dp[i][j][0]=10**18
            if j==5:
                dp[i][j][1]=10**18

ans=10**18
for i in range(6):
    ans=min(ans,min(dp[n-2][i]))
print(ans)