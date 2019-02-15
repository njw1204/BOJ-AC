while 1:
 ans=0
 x=[*map(int,input().split())]
 if x[0]==-1: break
 else: x=x[:-1]
 x.sort()
 p=1
 for i in range(len(x)):
  for j in range(p,len(x)):
   p=j+1
   if x[j]==x[i]*2:
    ans+=1
    break
   elif x[j]>x[i]*2:
    p=j
    break
 print(ans)