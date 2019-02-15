dp=[[0]*5 for i in range(101)]
dp[0][0]=1
dp[1][0]=1
dp[2][0]=1
dp[2][1]=1
dp[2][2]=1
dp[2][3]=1
dp[2][4]=1
for i in range(3,101):
  dp[i][0]=sum(dp[i-1])
  dp[i][4]=sum(dp[i-2])
  j=i-2
  while j>=0:
    dp[i][1]+=sum(dp[j])
    j-=2
  j=i-2
  while j>=0:
    dp[i][2]+=sum(dp[j])
    dp[i][3]+=sum(dp[j])
    j-=1

for i in range(int(input())):
  x=int(input())
  print(sum(dp[x]))