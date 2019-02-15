dp=[10**9]*1001
dp[1]=0
for i in range(2,1001):
    for j in range(1,i):
        cnt=(i-j)//j if i%j==0 else (i-j)//j+1
        d=dp[j]+1+cnt+(j*(cnt+1)-i)
        dp[i]=min(dp[i],d)
print(dp[int(input())])