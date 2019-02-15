a,b,c,n=map(int,input().split())
for i in range(300):
 for j in range(300):
  for k in range(300):
   if a*i+b*j+c*k==n:
    print(1)
    exit()
   elif a*i+b*j+c*k>n: break
print(0)