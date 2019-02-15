n,b=map(int,input().split())
d=[]
for i in range(n): d.append(int(input()))

a=10**9
for i in range(2**n):
    p=i
    t=0
    for j in range(n):
        if p&1: t+=d[j]
        p//=2
    if t>=b: a=min(a,t-b)

print(a)