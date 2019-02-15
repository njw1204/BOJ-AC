while 1:
  x=input()
  if x=='#': break
  a=0
  for i in x[:-1]:
    if i=='1': a+=1
    print(i,end='')
  if x[-1]=='e':
    if a%2: print(1)
    else: print(0)
  else:
    if a%2: print(0)
    else: print(1)