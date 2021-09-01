import sys
input=sys.stdin.readline

def need(enemy):
    global w; return enemy//w if enemy%w==0 else enemy//w+1

for t in range(int(input())):
    n,w=map(int,input().split())
    v=[[0]*3 for i in range(n+5)]
    dp=[[[10**5]*4 for i in range(n+5)] for j in range(4)]

    for r in range(1,3):
        x=[*map(int,input().split())]
        for i in range(1,n+1):
            v[i][r]=x[i-1]

    ans=10**6
    dp[0][1][0]=0
    dp[1][1][0]=need(v[1][1])
    dp[1][1][1]=need(v[1][1]+v[2][1])
    dp[2][1][0]=need(v[1][2])
    dp[2][1][2]=need(v[1][2]+v[2][2])
    dp[3][1][0]=need(v[1][1]+v[1][2])
    dp[3][1][1]=need(v[1][1]+v[2][1])+need(v[1][2])
    dp[3][1][2]=need(v[1][2]+v[2][2])+need(v[1][1])
    dp[3][1][3]=need(v[1][1]+v[2][1])+need(v[1][2]+v[2][2])

    if n==1:
        print(dp[3][1][0])
        continue

    for fi in range(4):
        for i in range(2,n+1):
            dp[fi][i][0] = min(dp[fi][i-1][3],
                               dp[fi][i-1][0] + need(v[i][1] + v[i][2]),
                               dp[fi][i-1][1] + need(v[i][2]),
                               dp[fi][i-1][2] + need(v[i][1]))
            dp[fi][i][1] = min(dp[fi][i-1][0] + need(v[i][1] + v[i%n+1][1]) + need(v[i][2]),
                               dp[fi][i-1][2] + need(v[i][1] + v[i%n+1][1]))
            dp[fi][i][2] = min(dp[fi][i-1][0] + need(v[i][2] + v[i%n+1][2]) + need(v[i][1]),
                               dp[fi][i-1][1] + need(v[i][2] + v[i%n+1][2]))
            dp[fi][i][3] = dp[fi][i-1][0] + need(v[i][1] + v[i%n+1][1]) + need(v[i][2] + v[i%n+1][2])

    print(min(dp[0][n][3],dp[1][n][2],dp[2][n][1],dp[3][n][0]))