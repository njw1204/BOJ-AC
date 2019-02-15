c=5*10**6+1;d=[0]*c;i=2
while i*i<=c-1:
 if d[i]>0:
  i+=1
  continue
 j=i*i
 while j<=c-1:
  if d[j]<1:d[j]=i
  j+=i
 i+=1
input()
for i in map(int,input().split()):
 while i>1:
  if d[i]<1:
   print(i)
   break
  a=d[i]
  i//=a
  print(a,end=" ")