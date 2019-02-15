a,b,n=0,0,int(input())
x=[*map(int,input().split())]
for i in x:
 a+=(1+i//30)*10
 b+=(1+i//60)*15
if a<b:
 print('Y',a)
elif b<a:
 print('M',b)
else:
 print('Y M',a)