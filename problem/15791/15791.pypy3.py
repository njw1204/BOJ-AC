n,m=map(int,input().split())
if not ((2 <= n <= 1000000) and (1 <= m <= n)): exit()
r=10**9+7
a,b,c=1,1,1
for i in range(2,n+1):
 a=a*i%r
 if i<=m: b=b*i%r
 if i<=n-m: c=c*i%r
print(a*pow(b*c%r,r-2,r)%r)