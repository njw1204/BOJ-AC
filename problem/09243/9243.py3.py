n,x,y=int(input())%2,input(),input()
if n==0:
  if x==y: print('Deletion succeeded')
  else: print('Deletion failed')
else:
  for i in range(len(x)):
    if x[i]==y[i]:
      print('Deletion failed')
      exit(0)
  print('Deletion succeeded')