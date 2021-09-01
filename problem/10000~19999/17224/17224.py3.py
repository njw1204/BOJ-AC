n,l,k=map(int,input().split())
oo=[]
for i in range(n):
    x,y=map(int,input().split())
    t=0
    if l>=x: t=100
    if l>=y: t+=40
    if t>0: oo.append(t)
oo.sort(reverse=True)
print(sum(oo[:k]))