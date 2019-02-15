x,mod=[*map(int,list(input()))],1000000
dp=[0]*5000
dp[0],dp[1]=1,1
if len(x)>1 and x[1]!=0 and (x[0]==1 or x[0]==2 and x[1]<7): dp[1]+=1

for i in range(2,len(x)):
 if x[i]==0: dp[i]=dp[i-2]
 elif x[i-1]==1 or x[i-1]==2 and x[i]<7:
  dp[i]=(dp[i-2]+dp[i-1])%mod
 else: dp[i]=dp[i-1]
if x==[0]: print(0)
else: print(dp[len(x)-1])