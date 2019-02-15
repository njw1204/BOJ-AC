n,m=map(int,input().split())
pos=0
x=[str(i) for i in range(1,n+1)]
r=[]
while pos<len(x):
 t=m-1
 while t:
  x.append(x[pos])
  pos+=1
  t-=1
 r.append(x[pos])
 pos+=1
print('<'+', '.join(r)+'>')