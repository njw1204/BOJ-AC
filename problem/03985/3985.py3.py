L=int(input())
N=int(input())
mP=-1
ans1=0
x=[0]*(L+1)
for i in range(N):
  a,b=map(int,input().split())
  if b-a>mP:
    ans1=i+1
    mP=b-a
  for j in range(a,b+1):
    if not x[j]: x[j]=i+1
print(ans1)
y=[0]*(N+1)
for i in x:
  y[i]+=1
mP=-1
ans2=0
for n,i in enumerate(y):
  if n==0: continue
  if i>mP:
    mP=i
    ans2=n
print(ans2)