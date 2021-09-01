x,y=map(int,input().split())
for i in range(2,y):
 if x%i==0:
  print("BAD", i)
  exit(0)
print("GOOD")