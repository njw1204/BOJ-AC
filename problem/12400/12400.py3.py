k='yhesocvxduiglbkrztnwjpfmaq'
for t in range(int(input())):
  print('Case #%d:'%(t+1),end=' ')
  for i in input():
    if i==' ': print(end=' ')
    else: print(k[ord(i)-ord('a')],end='')
  print()