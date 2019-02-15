a,x=map(int,input().split())
ans=0
for i in range(1,a+1):
 while i:
  if i%10==x: ans+=1
  i//=10
print(ans)