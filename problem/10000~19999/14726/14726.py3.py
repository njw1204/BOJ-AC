for _ in range(int(input())):
 no=list(map(int,list(input())))
 for i in range(0,16,2):
  no[i]*=2
  if no[i]>9: no[i]=no[i]%10+1
 print('T' if sum(no)%10==0 else 'F')