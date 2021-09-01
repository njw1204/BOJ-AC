from heapq import *
q=[]
n=int(input())
x=[*map(int,input().split())]
a=[0]*n
for i in range(n):
 heappush(q, -(x[i]-i))
 heappush(q, -(x[i]-i))
 heappop(q)
 a[i]=-heappop(q)
 heappush(q,-a[i])
for i in range(n-2,-1,-1):
 if a[i]>a[i+1]: a[i]=a[i+1]
r=0
for i in range(n):
 r+=abs(x[i]-a[i]-i)
print(r)