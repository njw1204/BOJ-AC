for _ in range(int(input())):
 __=[*map(int,input().split())]
 n=__[1]-__[0]
 left,right=1,100000
 while left<right:
  i=(left+right)//2
  if i%2:
   t=(i+1)//2
   x=t*(t+1)-t
  else:
   t=i//2
   x=t*(t+1)
  if n>x: left=i+1
  else: right=i
 print(left)