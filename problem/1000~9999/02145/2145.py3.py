while 1:
  x=int(input())
  if x==0: break
  while x>9:
    t=0
    while x:
      t+=x%10
      x//=10
    x=t
  print(x)