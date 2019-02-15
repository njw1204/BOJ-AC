m,n=map(int,input().split())
x=[]
visit=[[0]*m for i in range(n)]

for i in range(n): x.append([*map(int,input().split())])
Q=[]

cnt,cnt2=0,0

for n1,i in enumerate(x):
 for n2,j in enumerate(i):
  if j==1:
   Q.append((n1,n2))
   visit[n1][n2]=1
   cnt+=1
  elif j==-1:
   cnt2+=1
   visit[n1][n2]=-1
if cnt and cnt+cnt2==m*n:
 print(0)
 exit()
if cnt==0:
 print(-1)
 exit()

pos,ans=0,0
while pos<len(Q):
 t=Q[pos]
 if t[0]>0 and visit[t[0]-1][t[1]]==0:
   Q.append((t[0]-1,t[1]))
   visit[t[0]-1][t[1]]=visit[t[0]][t[1]]+1
   ans=max(ans,visit[t[0]][t[1]]+1)
 if t[1]>0 and visit[t[0]][t[1]-1]==0:
   Q.append((t[0],t[1]-1))
   visit[t[0]][t[1]-1]=visit[t[0]][t[1]]+1
   ans=max(ans,visit[t[0]][t[1]]+1)
 if t[0]<n-1 and visit[t[0]+1][t[1]]==0:
   Q.append((t[0]+1,t[1]))
   visit[t[0]+1][t[1]]=visit[t[0]][t[1]]+1
   ans=max(ans,visit[t[0]][t[1]]+1)
 if t[1]<m-1 and visit[t[0]][t[1]+1]==0:
   Q.append((t[0],t[1]+1))
   visit[t[0]][t[1]+1]=visit[t[0]][t[1]]+1
   ans=max(ans,visit[t[0]][t[1]]+1)
 pos+=1

for n1,i in enumerate(visit):
 for n2,j in enumerate(i):
  if j==0 and x[n1][n2]==0:
   print(-1)
   exit()

print(ans-1)
 