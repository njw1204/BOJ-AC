n,s,m=map(int,input().split())
v=[0]+[*map(int,input().split())]
dp=[[0]*1001 for i in range(101)]
if s+v[1]<=m:
    dp[1][s+v[1]]=1
    if n==1:
        print(s+v[1])
        exit(0)
if s-v[1]>=0:
    dp[1][s-v[1]]=1
    if n==1:
        print(s-v[1])
        exit(0)
ans=-1
for i in range(2,n+1):
    for j in range(0,m+1):
        if j+v[i]<=m: dp[i][j]|=dp[i-1][j+v[i]]
        if j-v[i]>=0: dp[i][j]|=dp[i-1][j-v[i]]
        if i==n and dp[i][j]: ans=max(ans,j)
print(ans)