def dfs(v):
 global n,m,L,V
 V[v]=True
 print(v,end=' ')
 for i in range(1,n+1):
  if L[v][i] and not V[i]: dfs(i)

def bfs(v):
 global n,m,L,V
 Q,pos=[v],0
 V[v]=True
 while pos<len(Q):
  print(Q[pos],end=' ')
  pos+=1
  for i in range(1,n+1):
   if L[Q[pos-1]][i] and not V[i]:
    Q.append(i)
    V[i]=True

n,m,v=map(int,input().split())
L=[[False]*(n+1) for i in range(n+1)]
for i in range(m):
 x,y=map(int,input().split())
 L[x][y]=L[y][x]=True

V=[False]*(n+1)
dfs(v)
print()
V=[False]*(n+1)
bfs(v)