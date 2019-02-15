for T in range(1,int(input())+1):
  h=int(input())
  print('Data Set %d:'%T)
  for i in input():
    if i=='c': h+=1
    else: h-=1
  print(h,end='\n\n')