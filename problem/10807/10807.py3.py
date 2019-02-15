n=int(input())
x=[*map(int,input().split())]
v=int(input())
ans=0
for i in x:
    if i==v: ans+=1
print(ans)