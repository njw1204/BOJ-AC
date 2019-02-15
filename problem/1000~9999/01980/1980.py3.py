a,b,t=map(int,input().split())
a,b=min(a,b),max(a,b)
for i in range(t):
 time=t-i
 aCnt=time//a
 while aCnt>=0:
  if (time-a*aCnt)%b==0:
   print(aCnt+(time-a*aCnt)//b,i)
   exit()
  aCnt-=1
print(0,t)