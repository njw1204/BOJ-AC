import sys
for _ in range(int(input())):
 m,n,x,y=map(int,sys.stdin.readline().split())
 if m<n: m,n,x,y=n,m,y,x
 i,j=x,x if x<=n else (x-1)%n+1
 ans,ori,cnt=i,j,0
 if not (1<=x<=m and 1<=y<=n):
  print(-1)
  continue
 while i-j!=x-y:
  cnt+=1
  j+=m-n
  if j>n: j=(j-1)%n+1
  if j==ori:
   ans=-1
   break
  ans+=m
 print(ans)