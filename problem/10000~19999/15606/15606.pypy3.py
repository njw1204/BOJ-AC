for _ in range(int(input())):
 a,b,c,w=map(int,input().split())
 ans=0
 for i in range(min(a,b,c),min(a,b,c)+1000000):
  req=max(0,i-a)+max(0,i-b)+max(0,i-c)
  if req>w: break
  ta=max(i,a)
  tb=max(i,b)
  tc=max(i,c)
  rew=w-req
  if ta==max(ta,tb,tc):
   ta+=rew
  elif tb==max(ta,tb,tc):
   tb+=rew
  else:
   tc+=rew
  ans=max(ans,ta*ta+tb*tb+tc*tc+i*7)
 print(ans)