import sys
input=sys.stdin.readline
n,k=map(int,input().split())
x=[[True]*205 for i in range(205)]
for i in range(k):
 a,b=map(int,input().split())
 x[a-1][b-1]=x[b-1][a-1]=False
z=0
for i in range(n-2):
 for j in range(i+1,n-1):
  for s in range(j+1,n):
   if x[i][j] and x[i][s] and x[j][s]: z+=1
print(z)