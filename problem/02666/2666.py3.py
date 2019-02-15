def distance(pre_x,pre_y,x,y):
    return abs(pre_x-x) + abs(pre_y-y)

n=int(input())
a,b=sorted(map(int,input().split()))
x=[0]
t=int(input())
for i in range(t):
    x.append(int(input()))

dp=[[[-1]*21 for i in range(21)] for j in range(21)]
dp[0][a][b]=0
ans=10**9

for i in range(1,t+1):
    for j in range(1,n+1):
        for k in range(j+1,n+1):
            if j!=x[i] and k!=x[i]:
                continue
            dp[i][j][k]=10**9
            for l in range(1,n+1):
                for m in range(l+1,n+1):
                    if dp[i-1][l][m]!=-1:
                        dp[i][j][k]=min(dp[i][j][k],dp[i-1][l][m]+distance(l,m,j,k))
            if i==t:
                ans=min(ans,dp[i][j][k])

print(ans)