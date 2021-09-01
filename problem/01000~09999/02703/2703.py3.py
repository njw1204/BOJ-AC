for _ in range(int(input())):
  x=list(input())
  y=input()
  for i in range(len(x)):
    if x[i]==' ': print(end=' ')
    else: print(y[ord(x[i])-ord('A')],end='')
  print()