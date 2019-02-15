s=input()
n=len(s)
pa=[[0]*n for i in range(n)]

for i in range(n):
    pa[i][i]=1
    if i<n-1 and s[i]==s[i+1]: pa[i][i+1]=1
for i in range(2,n):
    for j in range(n-i):
        if s[j]==s[j+i] and pa[j+1][j+i-1]: pa[j][j+i]=1

if pa[0][n-1]:
    print(1)
    exit(0)

dp=[10**9]*n
dp[0]=1
for i in range(1,n):
    if pa[0][i]:
        dp[i]=1
        continue
    for j in range(i):
        if pa[j+1][i]:
            dp[i]=min(dp[i],dp[j]+1)

print(dp[n-1])