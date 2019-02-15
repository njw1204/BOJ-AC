def BackTrack(x):
 global n,m,r,t,v
 last=''
 for i in range(n):
  if v[i] or last==t[i]: continue
  v[i]=1
  r.append(t[i])
  if x<m: BackTrack(x+1)
  else: print(' '.join(map(str,r)))
  last=r.pop()
  v[i]=0

r=[]
n,m=map(int,input().split())
v=[0]*n
t=sorted([*map(int,input().split())])
BackTrack(1)