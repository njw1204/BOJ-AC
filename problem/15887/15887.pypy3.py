n,x,r=int(input()),[*map(int,input().split())],[]
while x!=sorted(x):
 for i in range(1,n):
  if x[i-1]>x[i]:
   r+=[(i,i+1)]
   x[i-1],x[i]=x[i],x[i-1]
print(len(r))
for i,j in r: print(i,j)