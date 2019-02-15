n,m=int(input()),int(input())
link=[0]*n
for i in range(n):
  link[i]=[*map(bool,map(int,input().split()))]
plan=[*map(int,input().split())]
for i in range(n):
  for j in range(n):
    for k in range(n):
      if link[j][i] and link[i][k]:
        link[j][k]=True
        link[k][j]=True
for i in range(m-1):
  a,b=plan[i],plan[i+1]
  if a==b: continue
  if not link[a-1][b-1]:
    print('NO')
    exit()
print('YES')