P,C=[input() for _ in range(8)],0
for i in range(8):
 for j in range(8):
  if (i+j)%2<1 and P[i][j]=='F':C+=1
print(C)