N,K=map(int,input().split())
L=[1]*(N+1)
for j in range(2,N+1):
 if L[j]: key=j
 for i in range(key,N+1,key):
  if L[i]:
   L[i]=0
   K-=1
   if K==0:
    print(i)
    exit()