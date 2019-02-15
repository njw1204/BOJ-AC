for _ in range(int(input())):
  m,n,x,y=map(int,input().split())
  if not (1<=x<=m and 1<=y<=n):
    print(-1)
    continue

  if m<n:
    m,n=n,m
    x,y=y,x

  i=x
  if x<=n:
    j=x
  else:
    j=(x-1)%n+1

  ans,first_j=i,j
  while i-j!=x-y:
    j+=m-n
    if j>n:
      j=(j-1)%n+1
    if j==first_j:
      ans=-1
      break
    ans+=m

  print(ans)