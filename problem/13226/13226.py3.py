for _ in range(int(input())):
 a,b=map(int,input().split())
 ans=0
 for i in range(a,b+1):
  t=0
  j=2
  while j*j<i:
   if i%j==0: t+=2
   j+=1
  if i%(j*j)==0: t+=1
  if i==1: t=-1
  ans=max(ans,t+2)
 print(ans)