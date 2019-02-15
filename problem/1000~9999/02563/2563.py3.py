P=[0]*10000
for _ in range(int(input())):
 x,y=map(int,input().split())
 for i in range(y,y+10):
  for j in range(x,x+10):P[i*100+j]=1
print(sum(P))