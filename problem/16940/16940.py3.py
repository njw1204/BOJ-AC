from collections import *
import sys
input=sys.stdin.readline

n=int(input())
e=[set() for i in range(n+1)]
for i in range(n-1):
 x,y=map(int,input().split())
 e[x].add(y)
 e[y].add(x)

res=[*map(int,input().split())]
visit=[0]*(n+1)
visit[1]=1
q=deque()
q.append(1)

p=1
while q:
 i=q.popleft()
 while p<n:
  if res[p] in e[i]:
   visit[res[p]]=1
   q.append(res[p])
   p+=1
  else: break

print(+(sum(visit)==n))