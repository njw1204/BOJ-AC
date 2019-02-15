n,m=map(int,input().split())
x=[0]*n
can=[[True]*m for i in range(n)]
for i in range(n):
  x[i]=[*map(int,input().split())]
  maxPos,maxVal=-1,-1
  for j in range(m):
    if x[i][j]>maxVal:
      maxPos,maxVal=j,x[i][j]
  can[i][maxPos]=False
for i in range(m):
  maxPos,maxVal=-1,-1
  for j in range(n):
    if x[j][i]>maxVal:
      maxPos,maxVal=j,x[j][i]
  can[maxPos][i]=False
ans=0
for i in range(n):
  for j in range(m):
    if can[i][j]: ans+=x[i][j]
print(ans)