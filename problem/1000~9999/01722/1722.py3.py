import math

fact=[1]*21
for i in range(1,21):
    fact[i]=fact[i-1]*i

n=int(input())
query=[*map(int,input().split())]
if query[0]==1:
    order=query[1]
    query.pop(0)
    numList=[i for i in range(1,n+1)]
    for i in range(n):
        temp,cnt=0,0
        while temp<order:
            temp+=fact[n-1-i]
            cnt+=1
        order-=temp-fact[n-1-i]
        print(numList[cnt-1],end=' ')
        numList.pop(cnt-1)
else:
    ans=0
    query.pop(0)
    numList=[i for i in range(1,n+1)]
    for i in range(n):
        now=query[i]
        for j in range(len(numList)):
            if now==numList[j]:
                pos=j
                break
        ans+=pos*fact[n-1-i]
        numList.pop(pos)
    print(ans+1)