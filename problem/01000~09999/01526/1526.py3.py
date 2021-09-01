for i in range(int(input()),-1,-1):
 su=True
 t=i
 while i:
  if i%10!=4 and i%10!=7: su=False
  i//=10
 if su:
  print(t)
  exit()