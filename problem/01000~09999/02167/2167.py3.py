import sys
N,M=map(int,sys.stdin.readline().split())
dp=[[0]*M for _ in range(N)]
arr=[tuple(map(int,sys.stdin.readline().split())) for _ in range(N)]
for i in range(N):
 dp[i][0]=arr[i][0]
 for j in range(1,M):
  dp[i][j]=dp[i][j-1]+arr[i][j]
for _ in range(int(sys.stdin.readline())):
 r=0
 i,j,x,y=map(lambda x:x-1,map(int,sys.stdin.readline().split()))
 if j>0:
  for k in range(i,x+1):
   r+=dp[k][y]-dp[k][j-1]
 else:
  for k in range(i,x+1):
   r+=dp[k][y]
 sys.stdout.write(str(r)+'\n')