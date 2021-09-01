import sys
sys.setrecursionlimit(100000)

def DFS(i,j):
  global m,n,dp,field,visit
 
  if i==m and j==n: return 1
  if dp[i][j]!=-1: return dp[i][j]

  visit[i][j]=True
  dp[i][j]=0

  for di,dj in [[1,0],[-1,0],[0,1],[0,-1]]:
    if field[i+di][j+dj]<field[i][j] and not visit[i+di][j+dj]:
      dp[i][j]+=DFS(i+di,j+dj)

  visit[i][j]=False
  return dp[i][j]


m,n=map(int,input().split())
dp=[[-1]*(n+2) for i in range(m+2)]
visit=[[False]*(n+2) for i in range(m+2)]

field=[0]*(m+2)
field[0]=[11111]*(n+2)
field[m+1]=[11111]*(n+2)

for i in range(1,m+1):
  field[i]=[11111]
  field[i].extend([*map(int,input().split())])
  field[i].append(11111)

print(DFS(1,1))