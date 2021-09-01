n,m,k=map(int,input().split())
teamCnt=min(n//2,m)
k-=(n-teamCnt*2)+(m-teamCnt)
while k>0:
  teamCnt-=1
  k-=3
print(teamCnt)