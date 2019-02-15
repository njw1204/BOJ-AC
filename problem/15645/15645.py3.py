import sys
input=sys.stdin.readline

N=int(input())
X=[0]*N
for i in range(N): X[i]=[*map(int,input().split())]
dp=[[0]*3 for _ in range(N)]
dp[0]=[X[0][0],X[0][1],X[0][2]]
for i in range(1,N):
 dp[i][0]=max(dp[i-1][0],dp[i-1][1])+X[i][0]
 dp[i][1]=max(dp[i-1][0],dp[i-1][1],dp[i-1][2])+X[i][1]
 dp[i][2]=max(dp[i-1][1],dp[i-1][2])+X[i][2]
a=max(dp[-1])
dp[0]=[X[0][0],X[0][1],X[0][2]]
for i in range(1,N):
 dp[i][0]=min(dp[i-1][0],dp[i-1][1])+X[i][0]
 dp[i][1]=min(dp[i-1][0],dp[i-1][1],dp[i-1][2])+X[i][1]
 dp[i][2]=min(dp[i-1][1],dp[i-1][2])+X[i][2]
b=min(dp[-1])
print(a,b)