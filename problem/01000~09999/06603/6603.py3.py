def BackTrack(start,depth,maxDepth,T):
 global x,k
 for i in range(start,k-maxDepth+depth):
  T+=str(x[i])+' '
  if depth<maxDepth: BackTrack(i+1,depth+1,maxDepth,T)
  else: print(T)
  T=T[:-len(str(x[i]))-1]
 
while 1:
 x=[*map(int,input().split())]
 if x[0]==0: break
 k=x[0]
 del x[0]
 BackTrack(0,0,5,'')
 print()