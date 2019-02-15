for i in range(int(input())):
  T=input()
  lenT=len(T)
  ans=[0]*2

  ans[0]=[0]
  pos=2%lenT
  while pos:
   ans[0].append(pos)
   pos=(pos+2)%lenT

  for i in ans[0]:
    print(T[i],end='')
  print()

  ans[1]=[1%lenT]
  pos=3%lenT
  while pos!=1%lenT:
    ans[1].append(pos)
    pos=(pos+2)%lenT

  for i in ans[1]:
    print(T[i],end='')
  print()