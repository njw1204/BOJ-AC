n=int(input())
dp=[[0]*15 for i in range(n+5)]
for i in range(1,n+1):
 x=[*map(int,input().split())]
 for j in x[1:]:
  if i==1: dp[1][j]=-1
  else:
   for k in range(1,10):
    if k!=j and dp[i-1][k]:
     dp[i][j]=k
     break
if sum(dp[n])==0: print(-1)
else:
 ans=[]
 for i in range(1,10):
  if dp[n][i]:
   ans.append(i)
   while dp[n][i]!=-1:
    i=dp[n][i]
    n-=1
    ans.append(i)
   break
 for i in ans[::-1]:
  print(i)