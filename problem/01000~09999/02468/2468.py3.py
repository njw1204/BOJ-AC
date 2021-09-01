from collections import deque

def BFS(si,sj,pivot):
 global N,X,visit
 Q=deque()
 Q.append((si,sj))
 visit[si][sj]=True
 while Q:
  i,j=Q.popleft()
  if i>0 and X[i-1][j]>pivot and not visit[i-1][j]:
   Q.append((i-1,j))
   visit[i-1][j]=True
  if i<N-1 and X[i+1][j]>pivot and not visit[i+1][j]:
   Q.append((i+1,j))
   visit[i+1][j]=True
  if j>0 and X[i][j-1]>pivot and not visit[i][j-1]:
   Q.append((i,j-1))
   visit[i][j-1]=True
  if j<N-1 and X[i][j+1]>pivot and not visit[i][j+1]:
   Q.append((i,j+1))
   visit[i][j+1]=True

N=int(input())
X,ans=[],0
for i in range(N): X.append([*map(int,input().split())])

for k in range(100):
 visit=[[False]*N for i in range(N)]
 temp_ans=0
 for i in range(N):
  for j in range(N):
   if X[i][j]>k and not visit[i][j]:
    BFS(i,j,k)
    temp_ans+=1
    ans=max(temp_ans,ans)

print(ans)