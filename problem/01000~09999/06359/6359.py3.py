for _ in range(int(input())):
 N=int(input())
 X=[0]*(N+1)
 for i in range(1,N+1):
  for j in range(i,N+1,i):
   X[j]=0 if X[j] else 1
 print(sum(X))