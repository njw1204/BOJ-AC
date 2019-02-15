while 1:
  a=input().upper().split()
  if a[0]=='*': break
  c=a[0][0]
  f=True
  for i in a:
    if i[0]!=c:
      print('N')
      f=False
      break
  if f: print('Y')