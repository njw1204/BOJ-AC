n,r,x=int(input()),1,0
while n:
 x+=n%2*r
 n//=2
 r*=3
print(x)