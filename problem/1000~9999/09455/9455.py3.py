t=int(input())
for _ in range(t):
  m,n=map(int,input().split())
  x=[0]*m
  for i in range(m):
    x[i]=[*map(int,input().split())]
  ans=0
  for j in range(n):
    cnt=0
    for i in range(m-1,-1,-1):
      if x[i][j]==0: continue
      else:
        ans+=(m-1)-i-cnt
        cnt+=1
  print(ans)