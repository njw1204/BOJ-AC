y,x=map(int,input().split())
row,col=[False]*y,[False]*x
ans=0
for i in range(y):
 for n,j in enumerate(input()):
  if j=='X':
   row[i],col[n]=True,True
for i in range(y):
 for j in range(x):
  if row[i]==False and col[j]==False:
   row[i],col[j]=True,True
   ans+=1
for i in range(y):
 if row[i]==False: ans+=1
for j in range(x):
 if col[j]==False: ans+=1
print(ans)