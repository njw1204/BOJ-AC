n=int(input())
arr=[0]
dp=[[[0]*3 for i in range(n+1)] for j in range(n+1)]

for i in range(n):
    arr.append([*map(int,input().split())])

for i in range(1,n+1):
    dp[i][i]=[arr[i][0],arr[i][1],0]

for i in range(1,n):
    dp[i][i+1]=[arr[i][0],arr[i+1][1],arr[i][0]*arr[i+1][1]*arr[i][1]]

for size in range(2,n+1):
    for i in range(1,n-size+2):
        dp[i][i+size-1][0]=arr[i][0]
        dp[i][i+size-1][1]=arr[i+size-1][1]
        ans=10**18
        for j in range(i,i+size-1):
            x,y=dp[i][j],dp[j+1][i+size-1]
            ans=min(ans,x[0]*x[1]*y[1]+x[2]+y[2])
        dp[i][i+size-1][2]=ans

print(dp[1][n][2])