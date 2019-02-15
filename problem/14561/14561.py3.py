for i in range(int(input())):
  a,b=map(int,input().split())
  x=[]
  while a:
    x.append(a%b)
    a//=b
  if x==x[::-1]: print(1)
  else: print(0)