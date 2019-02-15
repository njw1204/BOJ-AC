n,m=map(int,input().split())
a=1
for i in map(int,input().split()):
 a=a*i%m
print(a)