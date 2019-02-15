dp=[1,1,1,2,2]
eval('dp.append(0),'*95)
for i in range(int(input())):
 N=int(input())
 for j in range(5,N): dp[j]=dp[j-1]+dp[j-5]
 print(dp[N-1])