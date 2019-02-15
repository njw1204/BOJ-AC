a,b=map(int,input().split())
for i in range(a+b):
 x,y=map(int,input().split())
 if x!=y:
  if i<a: print('Wrong Answer')
  else: print('Why Wrong!!!')
  exit()
print('Accepted')