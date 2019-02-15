a,b=map(int,input().split())
a,b=min(a,b),max(a,b)
if a<0 and b<0:
 a,b=-b,-a
 x=-((b*(b+1)-a*(a+1))//2+a)
elif a<0 and b>0:
 a=-a
 x=-(a*(a+1)//2)+b*(b+1)//2
else: x=(b*(b+1)-a*(a+1))//2+a
print(x)