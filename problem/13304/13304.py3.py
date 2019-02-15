import math
n,k=map(int,input().split())
x,ans=[],0
for i in range(n):
 s,y=map(int,input().split())
 if y<3: x.append(0)
 elif y<5 and s==0: x.append(1)
 elif y<5 and s==1: x.append(2)
 elif s==0: x.append(3)
 else: x.append(4)
for i in range(5): ans+=math.ceil(x.count(i)/k)
print(ans)