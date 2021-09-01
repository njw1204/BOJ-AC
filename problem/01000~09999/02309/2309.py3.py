x=[]
for i in range(9):
 x.append(int(input()))
x.sort()
asd=sum(x)
for i in range(8):
 for j in range(i+1,9):
  if asd-x[i]-x[j]==100:
   for k in range(9):
    if k!=i and k!=j:
     print(x[k])
   exit()