a,b,c=input(),input(),input()
dp=[[[0]*len(c) for j in range(len(b))] for i in range(len(a))]
for i in range(len(a)):
 for j in range(len(b)):
  for k in range(len(c)):
   if a[i]==b[j]==c[k]: dp[i][j][k]=dp[i-1][j-1][k-1]+1 if i and j and k else 1
   else:
    if i: dp[i][j][k]=dp[i-1][j][k]
    if j: dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k])
    if k: dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1])
print(dp[-1][-1][-1])