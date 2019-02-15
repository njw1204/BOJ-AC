N,FIND,UP,DOWN,LEFT,RIGHT=int(input()),int(input()),11,22,33,44
L=[[0]*N for _ in range(N)]
L[N//2][N//2],dir,length,prev_i,prev_j,next,cnt=1,UP,1,N//2,N//2,2,0

while 1:
  if next>N*N: break
  if dir==UP:
    for j in range(1,length+1):
      if next>N*N: break
      L[prev_i-j][prev_j]=next
      next+=1
    prev_i=prev_i-j
    dir=RIGHT
    cnt+=1
    if cnt==2:
      cnt=0
      length+=1
  elif dir==DOWN:
    for j in range(1,length+1):
      if next>N*N: break
      L[prev_i+j][prev_j]=next
      next+=1
    prev_i=prev_i+j
    dir=LEFT
    cnt+=1
    if cnt==2:
      cnt=0
      length+=1
  elif dir==LEFT:
    for j in range(1,length+1):
      if next>N*N: break
      L[prev_i][prev_j-j]=next
      next+=1
    prev_j=prev_j-j
    dir=UP
    cnt+=1
    if cnt==2:
      cnt=0
      length+=1
  elif dir==RIGHT:
    for j in range(1,length+1):
      if next>N*N: break
      L[prev_i][prev_j+j]=next
      next+=1
    prev_j=prev_j+j
    dir=DOWN
    cnt+=1
    if cnt==2:
      cnt=0
      length+=1

find_i,find_j=0,0
ans_str=''
for i in range(N):
  print(' '.join(map(str,L[i])))
  for j in range(N):
    X=L[i][j]
    if X==FIND: find_i,find_j=i,j

print(find_i+1,find_j+1)