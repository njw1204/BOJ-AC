def BackTrack(start,s,l):
 global x,a,f
 for i in range(start,l):
  if s+x[i]==f: a+=1
  if i+1<l: BackTrack(i+1,s+x[i],l)

n,f=map(int,input().split())
x,a=[*map(int,input().split())],0
BackTrack(0,0,len(x))
print(a)