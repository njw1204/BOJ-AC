n=int(input())
link=[[100]*n for i in range(n)]
for i in range(n):
  x=input()
  for j in range(n):
    if x[j]=='Y': link[i][j]=1

for i in range(n):
  for j in range(n):
    for k in range(n):
      if link[j][i]+link[i][k]<link[j][k]:
        link[j][k]=link[j][i]+link[i][k]
        link[k][j]=link[j][k]

ans=0
for i in range(n):
  t=0
  for j in range(n):
    if link[i][j]<=2 and i!=j: t+=1
  ans=max(t,ans)
print(ans)