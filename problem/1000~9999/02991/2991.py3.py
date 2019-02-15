a,b,c,d=map(int,input().split())
x=[2]*1001
for i in range(1,1001):
  x[i]=0
  if (i-1)%(a+b)<a: x[i]+=1
  if (i-1)%(c+d)<c: x[i]+=1
for i in map(int,input().split()):
  print(x[i])