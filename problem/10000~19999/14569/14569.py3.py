import sys
input=sys.stdin.readline

n=int(input())
subject=[0]*n
for i in range(n):
  x=[*map(int,input().split())]
  for j in x[1:]:
    subject[i]|=1<<j

m=int(input())
for i in range(m):
  x=[*map(int,input().split())]
  ans=0
  remainTime=0
  for j in x[1:]:
    remainTime|=1<<j
  for j in subject:
    tempRemainTime=remainTime|j
    if tempRemainTime==remainTime: ans+=1
  print(ans)