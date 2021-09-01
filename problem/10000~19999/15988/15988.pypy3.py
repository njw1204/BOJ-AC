dp=[0]*1000001
dp[1]=1
dp[2]=2
dp[3]=4
for i in range(4,1000001):
  for j in range(i-3,i):
    dp[i]+=dp[j]
  dp[i]%=1000000009
for i in range(int(input())):
  print(dp[int(input())])