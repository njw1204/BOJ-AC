x=[[0]*10 for _ in range(2)]
for i in range(2):
 for j in range(10): x[i][j]=int(input())
 x[i].sort()
print(x[0][-1]+x[0][-2]+x[0][-3],x[1][-1]+x[1][-2]+x[1][-3])