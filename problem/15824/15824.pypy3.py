def sm(x):
  x-=1
  if x==-1: x=1000000006
  return x

n,m,r=int(input()),1000000007,0
x=sorted(map(int,input().split()))
dp=[x[n-1]]*n
for i in range(n-2,-1,-1):
 dp[i]=(dp[i+1]*2%m+x[i])%m
for i in range(n-1):
 r=(r+(dp[i+1]-sm(pow(2,n-i-1,m))*(x[i]%m)%m)%m)%m
print(r)