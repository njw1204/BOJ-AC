n=int(input())
a,b=n//5,0
while a>=0:
 if (n-a*5)%3==0:
  print(a+(n-a*5)//3)
  exit()
 a-=1
print(-1)