import sys
input=sys.stdin.readline
for _ in range(int(input())):
 x=int(input())
 for i in range(2,65):
  li=[]
  t=x
  while t:
   li.append(t%i)
   t//=i
  if li==li[::-1]:
   print(1)
   break
  elif i==64: print(0)