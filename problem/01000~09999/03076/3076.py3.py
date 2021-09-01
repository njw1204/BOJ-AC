r,c=map(int,input().split())
a,b=map(int,input().split())
for i in range(r*a):
 for j in range(c*b):
  if ((i//a)+(j//b))%2==0: print(end="X")
  else: print(end=".")
 print()