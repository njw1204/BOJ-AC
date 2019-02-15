palin=[0]*20000
a,b=map(int,input().split())
palinCnt=0
for i in range(1,10001):
 palin[palinCnt]=int(str(i)[:-1]+str(i)[::-1])
 palinCnt+=1
 palin[palinCnt]=int(str(i)+str(i)[::-1])
 palinCnt+=1
 
for i in sorted(palin):
 if i<a: continue
 if i>b: break
 j,sosu=2,True
 while j*j<=i:
  if i%j==0:
   sosu=False
   break
  j+=1
 if sosu: print(i)
print(-1)