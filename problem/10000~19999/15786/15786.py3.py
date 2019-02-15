import sys
input=sys.stdin.readline
n,m=map(int,input().split())
k=input().rstrip()
for _ in range(m):
 p=0
 for i in input().rstrip():
  if i==k[p]: p+=1
  if p==n: break
 if p==n: print('true')
 else: print('false')