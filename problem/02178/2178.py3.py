from collections import deque

def BFS():
 global N,M,field
 Q=deque()
 visit=[[0]*M for i in range(N)]
 Q.append((0,0))
 visit[0][0]=1
 ans=1
 while Q:
  i,j=Q.popleft()
  if i==N-1 and j==M-1: return visit[i][j]
  if i-1>=0 and field[i-1][j] and not visit[i-1][j]:
   Q.append((i-1,j))
   visit[i-1][j]=visit[i][j]+1
   ans=visit[i-1][j]
  if i+1<N and field[i+1][j] and not visit[i+1][j]:
   Q.append((i+1,j))
   visit[i+1][j]=visit[i][j]+1
   ans=visit[i+1][j]
  if j-1>=0 and field[i][j-1] and not visit[i][j-1]:
   Q.append((i,j-1))
   visit[i][j-1]=visit[i][j]+1
   ans=visit[i][j-1]
  if j+1<M and field[i][j+1] and not visit[i][j+1]:
   Q.append((i,j+1))
   visit[i][j+1]=visit[i][j]+1
   ans=visit[i][j+1]
 return -1

N,M=map(int,input().split())
field=[0]*N
for i in range(N):
 field[i]=[*map(int,list(input()))]
print(BFS())