def gcd(a,b): return gcd(b%a,a) if a else b

N,A=map(int,input().split())
print(N-A,end=' ')
if gcd(N,A)!=1:
 print(-1)
 exit()

x,y=N,A
rx,ry=0,1
bx,by=1,0

while x%y>0:
  t=x//y
  rxt,ryt=bx-t*rx,by-t*ry
  bxt,byt=rx,ry
  rx,ry=rxt,ryt
  bx,by=bxt,byt
  t=x%y
  x=y
  y=t

print((ry+N)%N)