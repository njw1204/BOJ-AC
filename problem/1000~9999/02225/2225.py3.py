n,k=map(int,input().split())
mod=1000000000
x=[[0]*(k+1) for _ in range(n+1)]
for i in range(n+1): x[i][1]=x[i-1][1]+1
for i in range(2,k+1):
 for j in range(n+1):
   x[j][i]=x[j][i-1]
   if j>0: x[j][i]+=x[j-1][i]
   x[j][i]%=mod
print(x[n][k]-x[n-1][k] if x[n][k]>=x[n-1][k] else mod-(x[n-1][k]-x[n][k]))