x=[*map(int,input().split())]
y=[*map(int,input().split())]
xs,ys=0,0
for i,j in zip(x,y):
 xs+=i
 if xs>ys:
  print('Yes')
  exit()
 ys+=j
print('No')