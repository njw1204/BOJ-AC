def need(enemy):
    global w
    return enemy//w if enemy%w==0 else enemy//w+1

for t in range(int(input())):
    n,w=map(int,input().split())
    v=[[0]*3 for i in range(n+5)]
    dp=[[[10**6]*4 for i in range(n+5)] for j in range(4)]
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
        print(need(v[1][1]+v[1][2]))
        continue

    for fi in range(4):
        for i in range(2,n+1):
            for la in range(4):
                if i<n:
                    if la==0:
                        dp[fi][i][0] = min(dp[fi][i-1][3],
                                           dp[fi][i-1][0] + need(v[i][1] + v[i][2]),
                                           dp[fi][i-1][1] + need(v[i][2]),
                                           dp[fi][i-1][2] + need(v[i][1]))
                    elif la==1:
                        dp[fi][i][1] = min(dp[fi][i-1][0] + need(v[i][1] + v[i+1][1]) + need(v[i][2]),
                                           dp[fi][i-1][2] + need(v[i][1] + v[i+1][1]))
                    elif la==2:
                        dp[fi][i][2] = min(dp[fi][i-1][0] + need(v[i][2] + v[i+1][2]) + need(v[i][1]),
                                           dp[fi][i-1][1] + need(v[i][2] + v[i+1][2]))
                    elif la==3:
                        dp[fi][i][3] = dp[fi][i-1][0] + need(v[i][1] + v[i+1][1]) + need(v[i][2] + v[i+1][2])
                else:
                    if fi==0:
                        dp[0][n][3] = dp[0][n-1][0] + need(v[n][1] + v[1][1]) + need(v[n][2] + v[1][2])
                        ans = min(ans, dp[0][n][3])
                    elif fi==1:
                        dp[1][n][2] = min(dp[1][n-1][0] + need(v[n][2] + v[1][2]) + need(v[n][1]),
                                          dp[1][n-1][1] + need(v[n][2] + v[1][2]))
                        ans = min(ans, dp[1][n][2])
                    elif fi==2:
                        dp[2][n][1] = min(dp[2][n-1][0] + need(v[n][1] + v[1][1]) + need(v[n][2]),
                                          dp[2][n-1][2] + need(v[n][1] + v[1][1]))
                        ans = min(ans, dp[2][n][1])
                    elif fi==3:
                        dp[3][n][0] = min(dp[3][n-1][3],
                                          dp[3][n-1][0] + need(v[n][1] + v[n][2]),
                                          dp[3][n-1][1] + need(v[n][2]),
                                          dp[3][n-1][2] + need(v[n][1]))
                        ans = min(ans, dp[3][n][0])

    print(ans)