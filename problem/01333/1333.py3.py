cnt,mTime,bTime=map(int,input().split())
ans=0
for _ in range(cnt):
 ans+=mTime
 for i in range(5):
  if (ans+i)%bTime==0:
   print(ans+i)
   exit()
 ans+=5
while ans%bTime: ans+=1
print(ans)