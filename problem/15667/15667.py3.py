n=int(input())
if not (3<=n<=10101): exit()
for i in range(1,n):
 if i*i+i+1==n:
  print(i)
  exit()