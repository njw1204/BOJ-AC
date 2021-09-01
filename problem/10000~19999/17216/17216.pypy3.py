n=int(input())
x=[0]+[*map(int,input().split())]
dp=[0]*(n+5)
dp[1]=x[1]
ans=dp[1]
for i in range(2,n+1):
    dp[i]=x[i]
    for j in range(1,i):
        if x[j]>x[i]:
            dp[i]=max(dp[i],dp[j]+x[i])
    ans=max(ans,dp[i])
print(ans)