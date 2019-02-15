n,x=int(input()),input()
dp=[2**31]*(n+1)
dp[1]=0
for i in range(2,n+1):
 if x[i-1]=='B': key='J'
 elif x[i-1]=='O': key='B'
 else: key='O'
 for j in range(1,i):
  if x[j-1]==key: dp[i]=min(dp[i],dp[j]+(i-j)**2)
print(dp[n] if dp[n]!=2**31 else -1)