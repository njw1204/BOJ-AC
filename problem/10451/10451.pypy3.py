for _ in range(int(input())):
 n=int(input())
 x=[*map(int,input().split())]
 visit=[False]*(n+1)
 ans=0
 for i in range(1,n+1):
  if visit[i]: continue
  ans+=1
  visit[i]=True
  t=x[i-1]
  while visit[t]==False:
   visit[t]=True
   t=x[t-1]
 print(ans)