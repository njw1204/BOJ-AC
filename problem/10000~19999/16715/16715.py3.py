n=int(input())
x,y=0,0
for i in range(2,n+1):
 s,j=0,n
 while j:
  s+=j%i
  j//=i
 if s>x:
  x,y=s,i
print(x,y)