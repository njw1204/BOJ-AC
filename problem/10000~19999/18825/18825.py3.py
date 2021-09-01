input()
A=list(map(int,input().split()))
AA=sorted(A)
for i in A:
 for n,j in enumerate(AA):
  if i==j:
   print(n,end=' ')
   AA[n]=0
   break