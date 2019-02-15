import math
input()
ans=0
x=[*map(int,input().split())]
b,c=map(int,input().split())
for i in x:
 i-=min(i,b)
 ans+=math.ceil(i/c)+1
print(ans)