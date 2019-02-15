n,m=map(int,input().split())
x=[int(input()) for _ in range(n)]
for i in range(1,m+1):
 for j in range(n-1):
  if x[j]%i>x[j+1]%i:x[j],x[j+1]=x[j+1],x[j]
for i in x:print(i)