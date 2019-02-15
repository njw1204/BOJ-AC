N,L=map(int,input().split())
X=sorted(map(int,input().split()))
ans=1
last=X[0]-1+L
for i in range(1,N):
  if X[i]<=last:
    continue
  last=X[i]-1+L
  ans+=1
print(ans)