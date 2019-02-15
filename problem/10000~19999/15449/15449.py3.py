a=0
x=sorted(map(int,input().split()))
for i in range(5):
 for j in range(i+1,5):
  for k in range(j+1,5):
   if x[i]+x[j]>x[k]: a+=1
print(a)