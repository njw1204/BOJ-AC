prime=[True]*1001
prime[0]=prime[1]=False
i=2
while i*i<=1000:
 if prime[i]==False:
  i+=1
  continue
 j=i*i
 while j<=1000:
  prime[j]=False
  j+=i
 i+=1
for i in range(int(input())):
 ans=[3]
 x=int(input())-3
 for j in range(2,x//2+1):
  if prime[j] and prime[x-j]:
   ans.extend([j,x-j])
   break
 ans.sort()
 for j in ans: print(j,end=' ')
 print()