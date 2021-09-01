n=int(input())
x=[*map(int,input().split())]
dp=[10**18]*n
do=[[0]*3 for i in range(n)]
dp[0]=x[0]*3
do[0][1]=1
dp[1]=(x[0]+x[1]-min(x[0],x[1])*2)*3+min(x[0],x[1])*5
do[1][1]=x[1]-min(x[0],x[1])
do[1][2]=min(x[0],x[1])

for i in range(2,n):
 c=0
 c+=min(do[i-1][1],x[i])*2
 do[i][2]=min(do[i-1][1],x[i])
 x[i]-=min(do[i-1][1],x[i])
 c+=min(do[i-1][2],x[i])*2
 x[i]-=min(do[i-1][2],x[i])
 c+=x[i]*3
 do[i][1]=x[i]
 dp[i]=dp[i-1]+c
 
print(dp[n-1])