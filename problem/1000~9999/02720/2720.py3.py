for _ in range(int(input())):
 x,c=[25,10,5,1],int(input())
 for i in x:
  print('%d'%(c//i),end=' ')
  c%=i
 print()