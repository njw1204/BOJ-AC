import itertools,math
n=int(input())
x=[0]
for i in range(n): x.append(int(input()))
k=int(input())

dp=[[0]*k for i in range(2**n)]
dp[0][0]=1

for r in range(1,n+1):
    for i in itertools.combinations(range(1,n+1),r):
        used=set(i)
        origin_encode=0
        for m in used: origin_encode+=2**(m-1)

        for j in range(1,n+1):
            if j not in used: continue
            used.remove(j)
            encode=0
            for m in used: encode+=2**(m-1)
            used.add(j)

            num_len=len(str(x[j]))
            for m in range(k):
                dp[origin_encode][((m*(pow(10,num_len,k)))%k+x[j]%k)%k]+=dp[encode][m]

u,d=dp[2**n-1][0],sum(dp[2**n-1])
u,d=u//math.gcd(u,d),d//math.gcd(u,d)
print(u,d,sep="/")