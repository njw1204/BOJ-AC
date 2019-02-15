for T in range(1,int(input())+1):
 x=int(input())
 for i in range(x,0,-1):
  ans=i
  fail=False
  last=10
  while i:
   if i%10<=last:
    last=i%10
    i//=10
   else:
    fail=True
    break
  if not fail:
   print('Case #%d:'%T,ans)
   break