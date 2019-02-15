import sys
N=int(sys.stdin.readline())
L=[0]*N
dp=[[0]*N for i in range(N)]
dp[0][0]=1
for i in range(N): L[i]=[*map(int,sys.stdin.readline().split())]
for i in range(N):
 for j in range(N):
  if L[i][j]==0: break
  try: dp[i+L[i][j]][j]+=dp[i][j]
  except: pass
  try: dp[i][j+L[i][j]]+=dp[i][j]
  except: pass
print(dp[N-1][N-1])