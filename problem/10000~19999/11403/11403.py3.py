n=int(input())
x=[[False]*n for _ in range(n)]
xx=[[*map(int,input().split())] for _ in range(n)]
c=True
while c:
 c=False
 for i in range(n):
  for m,j in enumerate(xx[i]):
   if j==0: continue
   t=x[i][m]
   x[i][m]=True
   if t!=x[i][m]: c=True
   for k in range(n):
    t=x[i][k]
    x[i][k]=x[i][k] or x[m][k]
    if t!=x[i][k]: c=True
for i in range(n):
 for j in x[i]: print(+j,end=' ')
 print()