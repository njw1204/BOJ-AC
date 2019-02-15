dp=[[0]*31 for i in range(1001)]
arr=[0]
t,w=map(int,input().split())
for i in range(t): arr.append(int(input()))
dp[1][arr[1]-1]=1

for i in range(2,t+1):
  dp[i][0]=dp[i-1][0]
  if arr[i]==1: dp[i][0]+=1
  for j in range(1,w+1):
    dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])
    if j%2+1==arr[i]: dp[i][j]+=1

print(max(dp[t]))