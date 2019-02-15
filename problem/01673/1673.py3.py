try:
 while 1:
  n,k=map(int,input().split())
  chicken,stamp=n,n
  while stamp//k>0:
   chicken+=stamp//k
   stamp-=stamp//k*(k-1)
  print(chicken)
except: pass