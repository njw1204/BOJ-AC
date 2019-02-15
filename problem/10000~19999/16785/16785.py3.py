a,b,c=map(int,input().split())
x,d=0,0
while x<c:
 d+=1
 x+=a
 if d%7==0: x+=b
print(d)