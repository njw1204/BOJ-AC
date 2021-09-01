n,b,c=map(int,input().split())
if c>b: c=b
x=[*map(int,input().split())]
dp=[10**18]*10
do=[[0]*3 for i in range(10)]
dp[0]=x[0]*b
do[0][1]=1
dp[1]=(x[0]+x[1]-min(x[0],x[1])*2)*b+min(x[0],x[1])*(b+c)
do[1][1]=x[1]-min(x[0],x[1])
do[1][2]=min(x[0],x[1])

for i in range(2,n):
 l=0
 l+=min(do[(i-1)%2][1],x[i])*c
 do[i%2][2]=min(do[(i-1)%2][1],x[i])
 x[i]-=min(do[(i-1)%2][1],x[i])
 l+=min(do[(i-1)%2][2],x[i])*c
 x[i]-=min(do[(i-1)%2][2],x[i])
 l+=x[i]*b
 do[i%2][1]=x[i]
 dp[i%2]=dp[(i-1)%2]+l
 
print(dp[(n-1)%2])