x=[*map(int,input().split())]
ans2=[]
a,ans=int(input()),0
for i in range(len(x)-1):
 for j in range(i+1,len(x)):
  if x[i]+x[j]==a:
   if (min(x[i],x[j]),max(x[i],x[j])) not in ans2:
    ans2.append((min(x[i],x[j]),max(x[i],x[j])))
    ans+=1
for i in sorted(ans2):
 print(i[0],i[1])
print(ans)