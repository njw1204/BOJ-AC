n=int(input())
i=n-n%5
while i>=0:
 if (n-i)%2==0:
  print(i//5+(n-i)//2)
  exit()
 i-=5
print(-1)