dp=[1]*(int(input()))
x=[*map(int,input().split())]
for i in range(1,len(dp)):
 for j in range(i):
  if x[j]<x[i]:
   dp[i]=max(dp[i],dp[j]+1)
print(max(dp))