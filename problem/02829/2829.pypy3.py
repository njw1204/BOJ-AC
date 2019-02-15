n=int(input())
matrix=[0]*(n+1)
dp=[[[0]*2 for j in range(n+1)] for i in range(n+1)]
dp2=[[[0]*2 for j in range(n+1)] for i in range(n+1)]
for i in range(1,n+1):
    matrix[i]=[0]
    matrix[i].extend([*map(int,input().split())])

ans=0
for i in range(1,n+1):
    for j in range(1,n+1):
        dp[i][j][1]=dp2[i][j][1]=matrix[i][j]

for i in range(2,n+1):
    for j in range(i,n+1):
        for k in range(i,n+1):
            dp[j][k][i%2]=dp[j-1][k-1][(i-1)%2]+matrix[j][k]
            dp2[j][k][i%2]=dp2[j-1][k][(i-1)%2]+matrix[j][k-i+1]
            ans=max(ans,dp[j][k][i%2]-dp2[j][k][i%2])

print(ans)