def BackTrack(x,xx):
 global n,m,v,r,t
 for i in range(xx,n):
  if i>xx and t[i-1]==t[i]: continue
  v[i]=1
  r.append(t[i])
  if x<m: BackTrack(x+1,i)
  else: print(' '.join(map(str,r)))
  v[i]=0
  r.pop()

r=[]
n,m=map(int,input().split())
t=[i+1 for i in range(n)]
v=[0]*n
BackTrack(1,0)