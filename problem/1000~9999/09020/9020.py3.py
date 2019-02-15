import sys
sosu=[True]*10000
sosu[0],sosu[1]=False,False
i=2
while i*i<=9999:
 if sosu[i]==False:
  i+=1
  continue
 j=i*i
 while j<=9999:
  sosu[j]=False
  j+=i
 i+=1
for _ in range(int(input())):
 n=int(sys.stdin.readline())
 for diff in range(0,n//2):
  if sosu[n//2-diff] and sosu[n//2+diff]:
   ans1,ans2=n//2-diff,n//2+diff
   break
 print(ans1,ans2)