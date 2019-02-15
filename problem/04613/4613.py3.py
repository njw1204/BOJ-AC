while 1:
  x=input()
  a=0
  if x=='#': break
  for i in range(len(x)):
    if x[i]==' ': continue
    a+=(ord(x[i])-ord('A')+1)*(i+1)
  print(a)