x=[*map(int,input().split())]
while x!=[1,2,3,4,5]:
  for i in range(4):
    if x[i]>x[i+1]:
      x[i],x[i+1]=x[i+1],x[i]
      for j in x: print(j,end=' ')
      print()