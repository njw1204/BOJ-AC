res=[]
for i in range(int(input())):
  x=input()
  for j in range(ord('a'),ord('z')+1):
    x=x.replace(chr(j),' ')
  y=x.split()
  for j in y:
    res.append(int(j))
res.sort()
for i in res:
  print(i)