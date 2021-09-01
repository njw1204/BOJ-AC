import sys
try:
 while 1:
  x,y=map(int,sys.stdin.readline().split())
  z=int(y*100/x)
  if z>=99: print(-1)
  else:
   left,right=1,10000000000
   while left<right:
    mid=(left+right)//2
    if int(((y+mid)*100)/(x+mid))>z: right=mid
    else: left=mid+1
   print(left)
except: pass