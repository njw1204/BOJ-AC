def sums(x):
 a=0
 while x:
  a+=x%10
  x//=10
 return a
 
for i in range(int(input())):
 x=int(input())
 if sums(x)%2==1: print(x)
 else:
  m=9
  while sums(x*m)%2==0: m=m*10+9
  print(x*m)