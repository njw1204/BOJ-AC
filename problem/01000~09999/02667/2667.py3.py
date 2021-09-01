from collections import deque

def BFS(si,sj):
 global x,visit
 nn=0
 Q=deque()
 Q.append((si,sj))
 visit[si][sj]=True
 while Q:
  i,j=Q.popleft()
  nn+=1
  if x[i-1][j] and not visit[i-1][j]:
   Q.append((i-1,j))
   visit[i-1][j]=True
  if x[i+1][j] and not visit[i+1][j]:
   Q.append((i+1,j))
   visit[i+1][j]=True
  if x[i][j-1] and not visit[i][j-1]:
   Q.append((i,j-1))
   visit[i][j-1]=True
  if x[i][j+1] and not visit[i][j+1]:
   Q.append((i,j+1))
   visit[i][j+1]=True
 return nn

n=int(input())
ans=0
x=[0]*(n+2)
visit=[[False]*(n+2) for i in range(n+2)]
x[0]=[0]*(n+2)
for i in range(n):
 a=[0]
 a.extend([*map(int,list(input()))])
 a.append(0)
 x[i+1]=a[:]
x[-1]=[0]*(n+2)
ans2=[]
for i in range(1,n+1):
 for j in range(1,n+1):
  if x[i][j] and not visit[i][j]:
   ans2.append(BFS(i,j))
   ans+=1
print(ans)
ans2.sort()
for i in ans2:
 print(i)