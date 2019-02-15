prime=[True]*100001
primeCnts=[0]*100001
prime[0],prime[1]=False,False
  
def UnderPrime(num):
 if prime[num]:
  primeCnts[num]=1
  return False

 for i in range(2,num//2+1):
  if num%i==0:
   primeCnts[num]=primeCnts[num//i]+1
   break

 if prime[primeCnts[num]]: return True
 else: return False

a,b=map(int,input().split())
ans,i=0,2

while i*i<=100000:
 if prime[i]==False:
  i+=1
  continue
 j=i*2
 while j<=100000:
  prime[j]=False
  j+=i
 i+=1

for i in range(2,b+1):
 if UnderPrime(i) and i>=a: ans+=1
print(ans)