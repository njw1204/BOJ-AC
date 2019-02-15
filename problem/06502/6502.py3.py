T=1
while 1:
  L=[*map(int,input().split())]
  if L[0]==0: break
  if (L[0]*2)**2>=L[1]**2+L[2]**2: print('Pizza',T,'fits on the table.')
  else: print('Pizza',T,'does not fit on the table.')
  T+=1