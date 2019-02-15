n=int(input())
x=1
ans=0
for i in range(2,n+1):
 x*=i
 while x%10==0:
  x//=10
  ans+=1
print(ans)