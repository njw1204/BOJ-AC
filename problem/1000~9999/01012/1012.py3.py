import sys,copy,collections
input=sys.stdin.readline

def BFS(si,sj):
 global M,N,field,visit
 Q=collections.deque()
 Q.append((si,sj))
 visit[si][sj]=True
 while Q:
  i,j=Q.popleft()
  if i>0 and field[i-1][j] and not visit[i-1][j]:
   Q.append((i-1,j))
   visit[i-1][j]=True
  if i<M-1 and field[i+1][j] and not visit[i+1][j]:
   Q.append((i+1,j))
   visit[i+1][j]=True
  if j>0 and field[i][j-1] and not visit[i][j-1]:
   Q.append((i,j-1))
   visit[i][j-1]=True
  if j<N-1 and field[i][j+1] and not visit[i][j+1]:
   Q.append((i,j+1))
   visit[i][j+1]=True

for _ in range(int(input())):
 M,N,K=map(int,input().split())
 field=[[False]*N for i in range(M)]
 visit=copy.deepcopy(field)
 for i in range(K):
  a,b=map(int,input().split())
  field[a][b]=True
 ans=0
 for i in range(M):
  for j in range(N):
   if field[i][j] and not visit[i][j]:
    BFS(i,j)
    ans+=1
 print(ans)