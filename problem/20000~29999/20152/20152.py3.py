h,n=map(int,input().split())
if h==n:
    print(1)
    exit(0)
h,n=min(h,n),max(h,n)
dp=[[0]*(n+1) for i in range(n+1)]
dp[h][h]=1
for i in range(h,n+1):
    for j in range(h,n+1):
        if i==j==h or j>i: continue
        dp[i][j]=dp[i-1][j]+dp[i][j-1]
print(dp[n][n])