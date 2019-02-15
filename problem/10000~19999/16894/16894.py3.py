n=int(input())
i,j,x,y=2,2,'koosaga','cubelover'
while i*i<=n:
 if n%i==0:
  while j*j<=n//i:
   if n//i%j==0:
    print(x)
    exit()
   j+=1
  print(y)
  exit()
 i+=1
print(x)