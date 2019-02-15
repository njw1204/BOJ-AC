for _ in range(int(input())):
 x=int(input())
 for i in range(x):
  if i==0 or i==x-1: print('#'*x)
  else: print('#'+'J'*(x-2)+'#')
 print()