n,m=map(int,input().split())
x=[i for i in range(1,n+1)]
for i in range(m):
  a,b=map(int,input().split())
  x[a-1],x[b-1]=x[b-1],x[a-1]
for i in x: print(i,end=' ')