import math

def C(n,r):
    return math.factorial(n)//math.factorial(r)//math.factorial(n-r)

n=int(input())

dp=[[0]*55 for i in range(55)]

for i in range(1,53): # last card
    for j in range(1,i+1): # card count
        if i%4!=0 or j<4: # not bottom card
            for k in range(1,i):
                dp[i][j]+=dp[k][j-1]
                dp[i][j]%=10007
        else:
            dp[i][j]=C(i-4,j-4)%10007
            s=0
            for k in range(1,i-3):
                s+=dp[k][j-1]
                s%=10007
            for k in range(1,i-3):
                s+=dp[k][j-2]*3%10007
                s%=10007
            for k in range(1,i-3):
                s+=dp[k][j-3]*3%10007
                s%=10007
            dp[i][j]=(dp[i][j]+s)%10007

ans=0
for i in range(1,53):
    ans+=dp[i][n]
    ans%=10007
print(ans)