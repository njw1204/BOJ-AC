kinds,remain=map(int,input().split())
x=[]
dp=[[0]*(remain+1) for i in range(kinds)]
for i in range(kinds): x.append(tuple(map(int,input().split())))
for i in range(kinds):
 for j in range(remain+1):
  if i==0:
   if x[i][0]<=j: dp[i][j]=x[i][1]
  else:
   if j-x[i][0]>=0: dp[i][j]=max(dp[i-1][j],dp[i-1][j-x[i][0]]+x[i][1])
   else: dp[i][j]=dp[i-1][j]
print(dp[kinds-1][remain])