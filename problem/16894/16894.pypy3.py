n=int(input())
c,i=0,2
while i*i<=n:
 if n%i==0:
  n//=i
  j=2
  while j*j<=n:
   if n%j==0:
    print('koosaga')
    exit()
   j+=1
  print('cubelover')
  exit()
 i+=1
print('koosaga')