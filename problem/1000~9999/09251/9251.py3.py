a,b=input(),input()
dp=[[0]*len(b) for i in range(len(a))]
for i in range(len(a)):
 for j in range(len(b)):
  if a[i]==b[j]: dp[i][j]=dp[i-1][j-1]+1 if i and j else 1
  else:
   if i: dp[i][j]=dp[i-1][j]
   if j: dp[i][j]=max(dp[i][j],dp[i][j-1])
print(dp[-1][-1])