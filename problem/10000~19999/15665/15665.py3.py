def BackTrack(x):
 global n,m,r,t
 for i in range(n):
  if i and t[i-1]==t[i]: continue
  r.append(t[i])
  if x<m: BackTrack(x+1)
  else: print(' '.join(map(str,r)))
  r.pop()

r=[]
n,m=map(int,input().split())
t=sorted([*map(int,input().split())])
BackTrack(1)