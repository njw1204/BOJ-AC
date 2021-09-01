try:
 while True:
  x=[*map(int,input().split())]
  e=[0]*x[0]
  j=True
  for i in range(1,len(x)-1):
   d=abs(x[i]-x[i+1])
   if d>=x[0] or e[d]:
    j=False
    break
   e[d]=1
  if j: print('Jolly')
  else: print('Not jolly')   
except: pass