mod=10**9+9
dp1,dp2=[[0]*10 for i in range(2)],[[0]*26 for i in range(2)]
rdp1,rdp2=[0]*5,[0]*5
for i in range(10): dp1[1][i]=1
for i in range(26): dp2[1][i]=1
rdp1[1],rdp2[1]=10,26
for i in range(2,5):
    for j in range(10):
        dp1[i&1][j]=(rdp1[i-1]-dp1[(i-1)&1][j])%mod
        rdp1[i]=(rdp1[i]+dp1[i&1][j])%mod
    for j in range(26):
        dp2[i&1][j]=(rdp2[i-1]-dp2[(i-1)&1][j])%mod
        rdp2[i]=(rdp2[i]+dp2[i&1][j])%mod
lc="x"
cnt=0
ans=1
for i in input()+"x":
    if i==lc: cnt+=1
    else:
        if lc=="d":
            ans*=rdp1[cnt]
            ans%=mod
        elif lc=="c":
            ans*=rdp2[cnt]
            ans%=mod
        lc,cnt=i,1
print(ans)