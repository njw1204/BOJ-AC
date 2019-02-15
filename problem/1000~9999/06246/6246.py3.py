n,q=map(int,input().split())
x=[1]*(n+1)
for i in range(q):
 a,b=map(int,input().split())
 for j in range(a,n+1,b): x[j]=0
print(sum(x)-1)