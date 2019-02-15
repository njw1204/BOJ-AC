n,k=map(int,input().split())
mod=1000000007
k=min(k,n-k)
left,right=1,1
for i in range(n,n-k,-1):
    left*=i
    left%=mod
for i in range(1,k+1):
    right*=i
    right%=mod
right=pow(right,mod-2,mod)
print(left*right%mod)