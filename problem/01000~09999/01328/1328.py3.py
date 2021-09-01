def solve(n,l,r):
    global dp,mod

    if dp[n][l][r] == -1:
        if l < 1 or r < 1:
            dp[n][l][r] = 0
        elif n == 1:
            if l == r == 1:
                dp[n][l][r] = 1
            else:
                dp[n][l][r] = 0
        else:
            dp[n][l][r] = (solve(n-1,l,r)*(n-2) + solve(n-1,l-1,r) + solve(n-1,l,r-1)) % mod

    return dp[n][l][r]


n,l,r = map(int,input().split())
dp = [[[-1]*(r+1) for i in range(l+1)] for j in range(n+1)]
mod = 1000000007
print(solve(n,l,r))