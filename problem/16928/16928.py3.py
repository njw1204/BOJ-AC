from collections import deque

n=sum(map(int,input().split()))
visit=[0]*101
telpo=[i for i in range(101)]
for i in range(n):
 x,y=map(int,input().split())
 telpo[x]=y

visit[1]=1
q=deque()
q.append(1)

while q:
 i=q.popleft()
 if i==100: break
 for j in range(1,7):
  if i+j>100: continue
  p=telpo[i+j]
  if not visit[p]:
   visit[p]=visit[i]+1
   q.append(p)

print(visit[i]-1)