x=[*map(int,input().split())]
for i in range(1,len(x)):
 if x[i]<x[i-1]:
  print('Bad')
  exit()
print('Good')