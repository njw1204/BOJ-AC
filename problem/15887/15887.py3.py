n=int(input())
x=[*map(int,input().split())]
y=sorted(x)
res=[]
while x!=y:
  for i in range(n-1):
    if x[i]>x[i+1]:
      res.append((i+1,i+2))
      x[i],x[i+1]=x[i+1],x[i]
print(len(res))
for i,j in res: print(i,j)