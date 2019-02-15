def Fail():
 print("I'm Sorry Hansoo")
 exit()

T,D,ans,errorPos=input(),{},[],'0'
even=False if len(T)%2 else True
for i in T: D[i]=D.get(i,0)+1

if even:
 for i in D.values():
  if i%2: Fail()
else:
 errorCnt=0
 for key,i in D.items():
  if i%2:
   errorCnt+=1
   errorPos=key
   D[key]-=1
   if errorCnt==2: Fail()

for alpha,cnt in sorted(D.items(),key=lambda x:x[0]):
 for i in range(D[alpha]//2): ans+=alpha

if even: ans+=reversed(ans)
else:
 temp=reversed(ans)
 ans.append(errorPos)
 ans+=temp
print(''.join(ans))