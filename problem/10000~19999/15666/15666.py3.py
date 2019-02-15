def BackTrack(x,xx):
 global n,m,r,t
 for i in range(xx,n):
  if i>xx and t[i-1]==t[i]: continue
  r.append(t[i])
  if x<m: BackTrack(x+1,i)
  else: print(' '.join(map(str,r)))
  r.pop()

r=[]
n,m=map(int,input().split())
t=sorted([*map(int,input().split())])
BackTrack(1,0)