def gcd(a,b): return gcd(b,a%b) if b else a

N,A=map(int,input().split())
print(N-A,end=' ')
if gcd(N,A)>1:
 print(-1)
 exit()

x,y=N,A
rx,ry=0,1
bx,by=1,0

while x%y:
 t=x//y
 rx,ry,bx,by=bx-t*rx,by-t*ry,rx,ry
 t=x%y
 x=y
 y=t

print((ry+N)%N)