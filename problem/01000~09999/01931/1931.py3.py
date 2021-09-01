import sys
x=[]
last=0
ans=0
for i in range(int(input())):
 s,e=map(int,sys.stdin.readline().split())
 x.append([s,e])
x.sort(key=lambda x:(x[1],x[0]))
for i in x:
 if i[0]>=last:
  last=i[1]
  ans+=1
print(ans)