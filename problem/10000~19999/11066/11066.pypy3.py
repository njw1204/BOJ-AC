import sys
input=sys.stdin.readline

for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    dp=[[[0]*2 for i in range(n)] for j in range(n)]

    for i in range(n):
        dp[i][i]=[arr[i],0]

    for size in range(2,n+1):
        for i in range(n-size+1):
            dp[i][i+size-1][1]=10**9
            for j in range(i,i+size-1):
                dp[i][i+size-1][1]=min(dp[i][i+size-1][1],dp[i][j][1]+dp[j+1][i+size-1][1])
            dp[i][i+size-1][0]=dp[i][i][0]+dp[i+1][i+size-1][0]
            dp[i][i+size-1][1]+=dp[i][i+size-1][0]

    print(dp[0][n-1][1])





