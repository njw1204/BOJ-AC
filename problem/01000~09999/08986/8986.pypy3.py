def calc(x,dist):
    sd=0
    ans=0
    for i in x:
        ans+=abs(i-sd)
        sd+=dist
    return ans

n=int(input())
x=[*map(int,input().split())]
lo,hi=1,1000000000
while hi-lo>3:
    p,q=(lo*2+hi)//3,(lo+hi*2)//3
    if calc(x,p)>calc(x,q):
        lo=p
    else:
        hi=q

ans=10**30
for i in range(lo,hi+1):
    ans=min(ans,calc(x,i))
print(ans)