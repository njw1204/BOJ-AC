def BackTrack(x,xx):
 global n,m,v,r,t
 last=''
 for i in range(xx,n):
  if i>xx and last==t[i]: continue
  v[i]=1
  r.append(t[i])
  if x<m: BackTrack(x+1,i)
  else: print(' '.join(map(str,r)))
  v[i]=0
  last=r.pop()

r=[]
n,m=map(int,input().split())
t=sorted(map(int,input().split()))
v=[0]*n
BackTrack(1,0)