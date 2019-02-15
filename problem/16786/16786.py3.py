n=int(input())
x=[*map(int,input().split())];input()
for i in map(int,input().split()):
 if i<n and x[i-1]+1<x[i] or i==n and x[i-1]<2019:
  x[i-1]+=1
for i in x: print(i)