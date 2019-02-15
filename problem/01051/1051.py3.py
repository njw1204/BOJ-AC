n,m=map(int,input().split())
x=[]
for i in range(n):
 x.append([*map(int,list(input()))])
finans=0
for ans in range(1,51):
 if ans>n or ans>m: break
 success=False
 for i in range(n):
  if success: break
  for j in range(m):
   if i+ans-1>=n or j+ans-1>=m: break
   if x[i][j]==x[i+ans-1][j]==x[i][j+ans-1]==x[i+ans-1][j+ans-1]:
    success=True
    break
 if success: finans=ans
print(finans*finans)