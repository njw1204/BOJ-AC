a=input()
if '_' in a:
  for n,i in enumerate(a):
    if i.isupper() or a[0]=='_' or a[-1]=='_' or (i=='_' and a[n+1]=='_'):
      print('Error!')
      exit(0)
  t=0
  for i in a:
    if i=='_': t=1
    elif t==1:
      t=0
      print(i.upper(),end='')
    else: print(i,end='')
else:
  if a[0].isupper():
    print('Error!')
    exit(0)
  for i in a:
    if i.isupper(): print('_'+i.lower(),end='')
    else: print(i,end='')