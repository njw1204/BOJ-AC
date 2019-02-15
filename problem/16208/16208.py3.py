input();x=[*map(int,input().split())];s=sum(x);a=0
for i in x:
 s-=i
 a+=i*s
print(a)