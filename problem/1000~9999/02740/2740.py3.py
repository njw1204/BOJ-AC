n,m=map(int,input().split())
a=[0]*n
for i in range(n):
  a[i]=[*map(int,input().split())]
m,k=map(int,input().split())
b=[0]*m
for i in range(m):
  b[i]=[*map(int,input().split())]
for i in range(n):
  for j in range(k):
    s=0
    for v in range(m):
      s+=a[i][v]*b[v][j]
    print(s,end=' ')
  print()