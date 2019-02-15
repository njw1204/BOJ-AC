n=int(input())
x=[input().find('0') for _ in range(n-2)]
a=1e9
for i in range(4):
 s=0
 for j in x:
  o=abs(j-i)
  if i==0:s+=min(o,abs(j-4))
  elif i==3:s+=min(o,abs(j+1))
  else:s+=o
 a=min(a,s+n+2)
print(a)