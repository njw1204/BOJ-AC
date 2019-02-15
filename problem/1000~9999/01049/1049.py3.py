n,m=map(int,input().split())
aa,bb=11111,11111
for i in range(m):
  a,b=map(int,input().split())
  aa=min(a,aa)
  bb=min(b,bb)
dp=[0]*201
for i in range(1,201):
 dp[i]=dp[i-1]+bb
 if i>=6: dp[i]=min(dp[i],dp[i-6]+aa)
print(min(dp[n:]))