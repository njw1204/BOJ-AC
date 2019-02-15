from collections import deque

def BFS(start):
 global N,link
 ans=0
 visit=[0]*(N+1)
 Q=deque()
 Q.append(start)
 visit[start]=1
 while Q:
  now=Q.popleft()
  for i in link[now]:
   if visit[i]==0:
    Q.append(i)
    visit[i]=visit[now]+1
    ans+=visit[i]-1
 return ans

N,M=map(int,input().split())
bacon,baconX=10000,0
link=[[] for i in range(N+1)]
for i in range(M):
 a,b=map(int,input().split())
 link[a].append(b)
 link[b].append(a)
for i in range(1,N+1):
 t=BFS(i)
 if t<bacon:
  bacon=t
  baconX=i
print(baconX)