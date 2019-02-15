N=int(input())
if N==1:
 print(0)
 exit()
i,sosu=2,True
while i*i<=N:
 if N%i==0:
  sosu=False
  break
 i+=1
if sosu: i=N
print(N-N//i)