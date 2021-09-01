N,K=map(int,input().split())
for T in range(1,N+1):
 if N%T==0:
  K-=1
  if K==0:
   print(T)
   exit()
print(0)