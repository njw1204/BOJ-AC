import sys
input=sys.stdin.readline
mod=1000000007

dp=[[0]*2 for i in range(200000)]
dp[1][0]=1
dp[2][0]=1
dp[2][1]=1

for i in range(3,200000):
    dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod
    dp[i][1]=(dp[i-2][0]+dp[i-2][1])%mod

for _ in range(int(input())):
    n=int(input())
    print((dp[n][0]+dp[n][1])%mod)