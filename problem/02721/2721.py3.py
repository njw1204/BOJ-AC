for _ in range(int(input())):
  x=int(input())
  a=0
  for i in range(1,x+1):
    a+=i*(i+1)*(i+2)//2
  print(a)