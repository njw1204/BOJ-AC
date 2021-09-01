def bfs(start,dest):
 visit=[0]*200001
 Q,pos=[start],0
 visit[start]=1

 while 1:
  start=Q[pos]
  if start==dest: return visit[start]-1
  if start<dest and not visit[start+1]:
    Q.append(start+1)
    visit[start+1]=visit[start]+1
  if start>0 and not visit[start-1]:
    Q.append(start-1)
    visit[start-1]=visit[start]+1
  if start<dest and not visit[start*2]:
    Q.append(start*2)
    visit[start*2]=visit[start]+1
  pos+=1

a,b=map(int,input().split())
print(bfs(a,b))