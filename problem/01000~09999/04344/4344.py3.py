for i in range(int(input())):
 x=[*map(int,input().split())]
 a=sum(x[1:])
 p=a/x[0]
 c=0
 for i in range(1,len(x)):
  if x[i]>p: c+=1
 print('%.3f%%'%(c/(len(x)-1)*100))