x,y=map(int,input().split())
i=1
while True:
 if i-i*x/y>=1:
  print(i)
  exit(0)
 i+=1