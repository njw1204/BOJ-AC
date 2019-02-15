x,ans=[*map(int,input().split())],0
for i in range(3):
 for j in range(i+1,4):
  xx,yy=99,99
  for k in range(4):
   if k==i or k==j: xx=min(xx,x[k])
   else: yy=min(yy,x[k])
  ans=max(ans,xx*yy)
print(ans)