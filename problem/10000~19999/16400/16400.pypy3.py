n=int(input())

sosu=[True]*(n+1)
sosu[0]=sosu[1]=False
i=2
while i*i<=n:
    if sosu[i]==False:
        i+=1
        continue
    j=i*i
    while j<=n:
        sosu[j]=False
        j+=i
    i+=1

dp=[0]*(n+1)
dp[0]=1

for i in range(1,n+1):
    if not sosu[i]: continue
    for j in range(1,n+1):
        if j-i>=0:
            dp[j]+=dp[j-i]
            dp[j]%=123456789

print(dp[n])