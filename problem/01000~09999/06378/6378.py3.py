while 1:
 n=input()
 if n=='0': break
 while int(n)>9:
  t=0
  for i in n: t+=int(i)
  n=str(t)
 print(n)