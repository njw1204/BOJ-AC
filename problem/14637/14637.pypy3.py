n,t=map(int,input().split())
x=[]
mp=10**6
for i in range(n):
    x.append([*map(int,input().split())])
    mp=min(mp,x[i][1])
left,right=-mp,10**7
while abs(left-right)>=0.00000001:
    mid=(left+right)/2
    hour=0
    for i in x:
        hour+=i[0]/(i[1]+mid)
    if hour>=t: left=mid
    else: right=mid
print(left)