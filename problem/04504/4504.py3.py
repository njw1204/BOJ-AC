n=int(input())
while 1:
 x=int(input())
 if x==0: break
 if x%n==0:
  print(x,'is a multiple of',n,end='.\n')
 else:
  print(x,'is NOT a multiple of',n,end='.\n')