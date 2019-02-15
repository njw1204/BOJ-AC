import sys
for i in range(int(input())):
  N=int(input())
  cost=list(map(int,sys.stdin.readline().split()))
  maxStartFrom=[0 for k in range(N)]
  money,stock=0,0
  maxStartFrom[N-1]=cost[N-1]
  for j in range(N-2,0,-1):
    if cost[j]>maxStartFrom[j+1]: maxStartFrom[j]=cost[j]
    else: maxStartFrom[j]=maxStartFrom[j+1]
  for j in range(N):
    if j<N-1 and cost[j]<maxStartFrom[j+1]:
      money-=cost[j]
      stock+=1
    elif stock>0:
      money+=cost[j]*stock
      stock=0
  print(money)