x=[9,4,8,7,2,1,6,5,0,3]
ans=[]
m,n=map(int,input().split())
for i in range(m,n+1):
 if i>9: t=str(x[i//10])+str(x[i%10])
 else: t=str(x[i])
 ans.append((i,t))
counter=0
for i in sorted(ans,key=lambda x:x[1]):
 print(i[0],end=' ')
 counter+=1
 if counter%10==0: print()