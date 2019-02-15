n=int(input())
w=[0]*n
for p,i in enumerate(map(int,input().split())):
 diff=p-i+1
 if diff>=0: w[diff]=1
 else: w[diff+n]=1
for i in range(n):
 if w[i]<1:
  print(i)
  exit(0)
print(-1)