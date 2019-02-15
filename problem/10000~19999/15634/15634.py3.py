N,M=map(int,input().split())
x=[]
for i in range(N): x.append(list(input()))
for i in range(N):
 for j in range(M):
  if x[i][j]=='#': x[i][j]=1
  else: x[i][j]=0
state=[[0]*M for i in range(N)]
i,j,cnt=0,-1,0
while cnt<N*M:
 cnt+=1
 if i%2==0:
  if j==M-1:
   i+=1
   state[i][j]+=1
   print('D',end='')
  else:
   j+=1
   state[i][j]+=1
   print('R',end='')
 else:
  if j==0:
   i+=1
   state[i][j]+=1
   print('D',end='')
  else:
   j-=1
   state[i][j]+=1
   print('L',end='')
 if state[i][j]%2!=x[i][j]:
  if j<M-1 and i%2==0:
   print('RL',end='')
   state[i][j+1]+=1
  elif j>0 and i%2:
   print('LR',end='')
   state[i][j-1]+=1
  else:
   print('DU',end='')
   if i+1<N: state[i+1][j]+=1