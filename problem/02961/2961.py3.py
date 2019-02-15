N=int(input())
X=[]
for i in range(N):
  X.append([*map(int,input().split())])
ans=-1
for i in range(1,2**N):
  sour,bitter,idx=1,0,0
  while i:
    if i&1:
      sour*=X[idx][0]
      bitter+=X[idx][1]
      if ans==-1: ans=abs(sour-bitter)
      else: ans=min(ans,abs(sour-bitter))
    idx+=1
    i>>=1
print(ans)