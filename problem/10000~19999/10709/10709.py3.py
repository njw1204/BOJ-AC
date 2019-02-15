h,w=map(int,input().split())
for i in range(h):
  b=-1
  for n,j in enumerate(input()):
    if n: print(end=' ')
    if b==-1 and j=='.': print(-1,end='')
    elif j=='c':
      b=n
      print(0,end='')
    else:
      print(n-b,end='')
  print()