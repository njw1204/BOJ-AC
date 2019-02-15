n=int(input())
ans=0
for i in range(n):
 x=[*map(int,input().split())]
 if len(set(x))==1:
  ans=max(ans,50000+x[0]*5000)
 elif len(set(x))==2:
  if x.count(x[0])==3: key=x[0]
  elif x.count(x[1])==3: key=x[1]
  elif x.count(x[2])==3: key=x[2]
  elif x.count(x[3])==3: key=x[3]
  else:
   temp=2000
   for _ in set(x): temp+=500*_
   ans=max(ans,temp)
   continue
  ans=max(ans,10000+key*1000)
 elif len(set(x))==3:
  if x.count(x[0])==2: key=x[0]
  elif x.count(x[1])==2: key=x[1]
  else: key=x[2]
  ans=max(ans,1000+key*100)
 else:
   ans=max(ans,max(x)*100)
print(ans)
 