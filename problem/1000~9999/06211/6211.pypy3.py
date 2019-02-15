c,b=map(int,input().split())
x=[*map(int,input().split())]
oioi=set()

ans=0
oioi.add(0)
for i in x:
    tmp=[]
    for j in oioi:
        tmp.append(i+j)
        if i+j<=c: ans=max(ans,i+j)
    for j in tmp:
        oioi.add(j)

print(ans)