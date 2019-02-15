for _ in range(int(input())):
 n,w,p=int(input()),1,0
 while n:
  if n%2: print(p,end=' ')
  n//=2
  w*=2
  p+=1