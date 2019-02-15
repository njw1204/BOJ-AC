x=[]
for i in range(4):
    x.append(int(input()))
x.sort()
ans=sum(x[1:])
x=[]
for i in range(2):
    x.append(int(input()))
ans+=max(x)
print(ans)