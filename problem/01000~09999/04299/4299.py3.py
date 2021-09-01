s,d=map(int,input().split())
a=(s+d)//2
b=s-a
if a+b!=s or a-b!=d or a<0 or b<0:
    print(-1)
else:
    print(a,b)