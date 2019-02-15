prime=[True]*246913
primeCnt=[0]*246913
prime[0],prime[1],primeCnt[2],i=False,False,1,2

while i*i<=246912:
 if prime[i]==False:
  i+=1
  continue
 j=i*2
 while j<=246912:
  prime[j]=False
  j+=i
 i+=1

for i in range(3,246913): primeCnt[i]=primeCnt[i-1]+prime[i]

while 1:
 n=int(input())
 if n==0: break
 print(primeCnt[n*2]-primeCnt[n])