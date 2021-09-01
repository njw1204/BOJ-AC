n=int(input())
dp=[[1]*3 for i in range(2)]
for i in range(1,n):
 dp[i%2][0]=(dp[(i-1)%2][0]+dp[(i-1)%2][1]+dp[(i-1)%2][2])%9901
 dp[i%2][1]=(dp[(i-1)%2][0]+dp[(i-1)%2][2])%9901
 dp[i%2][2]=(dp[(i-1)%2][0]+dp[(i-1)%2][1])%9901
n-=1
print((dp[n%2][0]+dp[n%2][1]+dp[n%2][2])%9901)