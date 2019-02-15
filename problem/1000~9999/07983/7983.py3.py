import sys
input=sys.stdin.readline
n=int(input())
x=[0]*n
for i in range(n):
 x[i]=[*map(int,input().split())]
x.sort(key=lambda x:-x[1])
left=10**10
for i in range(n):
 if x[i][1]<left:
  left=x[i][1]-x[i][0]+1
 else:
  left=left-x[i][0]
print(left-1)