i=0
x=input()
while i<len(x):
  print(x[i],end='')
  if x[i] in ['a','e','i','o','u']: i+=2
  i+=1