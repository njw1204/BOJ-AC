import math

def DP(start,end,remain):
  global dp
  if start>end: return 0 if remain else 1
  if dp[start][remain]: return dp[start][remain]
  if math.ceil((end-start+1)/2)<remain: return 0
  if remain==1: return end-start+1
  dp[start][remain]=DP(start+1,end,remain)+DP(start+2,end,remain-1)
  dp[start][remain]%=1000000003
  return dp[start][remain]

N,K=int(input()),int(input())
dp=[[0]*(K+2) for i in range(N+2)]
ans=DP(1,N-1,K)
dp=[[0]*(K+2) for i in range(N+2)]
ans+=DP(2,N-2,K-1)
ans%=1000000003
print(ans)