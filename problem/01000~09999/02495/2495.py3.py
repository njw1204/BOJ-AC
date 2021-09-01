for _ in range(3):
  a=1
  b=1
  t=0
  for i in input():
    if b==1:
      t=1
      b=i
    elif i==b:
      t+=1
      a=max(a,t)
    else:
      t=1
      b=i
  print(a)