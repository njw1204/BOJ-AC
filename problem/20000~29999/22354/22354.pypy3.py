n=int(input())
a=input()
v=[*map(int,input().split())]
vv=[]
for i in range(n):
    if i==0:
        vv.append(v[i])
    else:
        if a[i]==a[i-1]:
            vv[-1]=max(vv[-1],v[i])
        else:
            vv.append(v[i])

cancount=(len(vv)-1)//2
vv=vv[1:-1]
vv.sort(reverse=True)
print(sum(vv[:cancount]))