from collections import deque

def BFS(si,sj):
  global N,M,tongro,visit
  Q=deque()
  Q.append((si,sj))
  visit[si][sj]=1
  visitCnt=1
  while Q:
    i,j=Q.popleft()
    if tongro[i-1][j] and not visit[i-1][j]:
      Q.append((i-1,j))
      visit[i-1][j]=1
      visitCnt+=1
    if tongro[i+1][j] and not visit[i+1][j]:
      Q.append((i+1,j))
      visit[i+1][j]=1
      visitCnt+=1
    if tongro[i][j-1] and not visit[i][j-1]:
      Q.append((i,j-1))
      visit[i][j-1]=1
      visitCnt+=1
    if tongro[i][j+1] and not visit[i][j+1]:
      Q.append((i,j+1))
      visit[i][j+1]=1
      visitCnt+=1
  return visitCnt

N,M,K=map(int,input().split())
ans=0
tongro=[[0]*(M+2) for i in range(N+2)]
visit=[[0]*(M+2) for i in range(N+2)]

for i in range(K):
  a,b=map(int,input().split())
  tongro[a][b]=1

for i in range(1,N+1):
  for j in range(1,M+1):
    if tongro[i][j] and visit[i][j]==0: ans=max(ans,BFS(i,j))

print(ans)
