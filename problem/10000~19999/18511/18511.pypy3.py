n,k=map(int,input().split())
x=[*map(int,input().split())]
forbidden=[False]*10
for i in range(0,10):
    if i not in x:
        forbidden[i]=True

ans=-1
for i in range(1,n+1):
    fail=False
    t=i
    while i:
        if forbidden[i%10]:
            fail=True
            break
        i//=10
    if not fail: ans=t

print(ans)