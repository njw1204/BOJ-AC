X=int(input())
a=[*map(int,input().split())]
b=[*map(int,input().split())]
a.sort()
b.sort(reverse=True)
ans=0
for i in range(X):
  ans+=a[i]*b[i]
print(ans)