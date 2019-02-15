x=[]
for i in range(int(input())):
 x1,y1,x2,y2=map(int,input().split())
 x.append((x1,y1,x2,y2))
x.sort(reverse=True,key=lambda k:(k[2]-k[0])*(k[3]-k[1]))
ans=0
for i in range(501):
 for j in range(501):
  for k in x:
   if k[0]<=i<k[2] and k[1]<=j<k[3]:
    ans+=1
    break
print(ans)