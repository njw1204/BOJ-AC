field=[[0]*100 for i in range(100)]
n,m=map(int,input().split())
for i in range(n):
 x,y,a,b=map(int,input().split())
 for j in range(x-1,a):
  for k in range(y-1,b):
   field[j][k]+=1
a=0
for i in range(100):
 for j in range(100):
  if field[i][j]>m:a+=1
print(a)