N=int(input())
wall=[1]*(N-1)
for _ in range(int(input())):
 x,y=map(int,input().split())
 for i in range(x-1,y-1):
  wall[i]=0
print(sum(wall)+1)