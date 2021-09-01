n=int(input())
a=0
for i in range(1,n+1):
 for j in range(1,i+1):
  if i%j==0 and i//j>=j: a+=1
print(a)