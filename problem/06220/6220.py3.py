c,n=map(int,input().split())
d=[]
for i in range(n): d.append(int(input()))
dp=[10**6]*(c+1)
dp[0]=0
for i in range(1,c+1):
    for j in d:
        if i-j>=0:
            dp[i]=min(dp[i],dp[i-j]+1)
print(dp[c])