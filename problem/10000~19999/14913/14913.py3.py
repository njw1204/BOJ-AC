a,d,n=map(int,input().split())
if (n-a)%d==0:
 if d<0 and n<=a or d>0 and n>=a:
  print((n-a)//d+1)
  exit()
print('X')