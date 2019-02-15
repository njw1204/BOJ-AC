a,b,c=map(int,input().split())
x=sorted(map(int,input().split()),reverse=True)
y=sorted(map(int,input().split()),reverse=True)
z=sorted(map(int,input().split()),reverse=True)
ans=sum(x)+sum(y)+sum(z)
print(ans)
for i in range(min([len(x),len(y),len(z)])):
 ans-=(x[i]+y[i]+z[i])//10
print(ans)