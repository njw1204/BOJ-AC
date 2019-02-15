n=int(input())
a=[0 for i in range(n)]
b=list(map(int,input().split()))
a[0]=b[0]
print(a[0],end=' ')
for i in range(1,n):
  a[i]=(i+1)*b[i]
  for j in range(i):
    a[i]-=a[j]
  print(a[i],end=' ')