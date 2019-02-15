def Hanoi(n,fr,st,to):
  if n==1:
    print(fr,to)
  else:
    Hanoi(n-1,fr,to,st)
    print(fr,to)
    Hanoi(n-1,st,fr,to)

n=int(input())
print(2**n-1)
Hanoi(n,1,2,3)