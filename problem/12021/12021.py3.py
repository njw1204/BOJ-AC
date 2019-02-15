a,b=map(int,input().split())
while 1:
 aa=round((a+b)/2,3)
 bb=round(2*a*b/(a+b),3)
 if a==aa and b==bb:
  print('%.3f %.3f'%(aa,bb))
  break
 a,b=aa,bb