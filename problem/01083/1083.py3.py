n=int(input())
x=[*map(int,input().split())]
s=int(input())

base=0
while s>0 and base<n-1:
    mi,mp=-1,-1
    for i in range(base,base+s+1):
        if i>=n: break
        if x[i]>mi:
            mi,mp=x[i],i
    s-=mp-base
    x.pop(mp)
    x.insert(base,mi)
    base+=1

for i in x: print(i,end=" ")