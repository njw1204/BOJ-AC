def comb(n,r):
    global fact,mod
    return fact[n] * pow(fact[n-r],mod-2,mod) % mod * pow(fact[r],mod-2,mod) % mod

def comb_with_repeat(n,r):
    return comb(n+r-1,r)

mod=10**9+7
fact=[1]*2000001
for i in range(1,2000001):
    fact[i]=fact[i-1]*i%mod

n,mi,m,k=map(int,input().split())
m-=mi
k-=mi*n

ans=comb_with_repeat(n,k)

presum=m+1
selnode=1
while presum<=k:
    kk=k-presum
    if selnode%2:
        ans-=comb_with_repeat(n,kk)*comb(n,selnode)%mod
        ans+=mod
        ans%=mod
    else:
        ans+=comb_with_repeat(n,kk)*comb(n,selnode)%mod
        ans%=mod

    presum+=m+1
    selnode+=1

print(ans)