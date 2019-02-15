n,k=map(int,input().split())
x=[*map(int,input().split())]
o=[0]*n
for i in range(1,n):
 o[i-1]=x[i]-x[i-1]
o.sort(reverse=True)
print(sum(o[k-1:]))