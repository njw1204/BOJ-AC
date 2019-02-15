def bfs(start,dest):
 V=[0]*200001
 Q,pos=[start],0
 V[start]=1
 while 1:
  start=Q[pos]
  if start==dest: return V[start]-1
  if start<dest and not V[start+1]:
    Q.append(start+1)
    V[start+1]=V[start]+1
  if start>0 and not V[start-1]:
    Q.append(start-1)
    V[start-1]=V[start]+1
  if start<dest and not V[start*2]:
    Q.append(start*2)
    V[start*2]=V[start]+1
  pos+=1

a,b=map(int,input().split())
print(bfs(a,b))