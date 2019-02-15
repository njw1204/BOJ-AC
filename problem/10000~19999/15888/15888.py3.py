a,b,c=map(int,input().split())
s=b**2-4*a*c
if s<=0:
 print('둘다틀렸근')
 exit(0)
if (s**0.5)**2!=s:
 print('둘다틀렸근')
 exit(0)
ss=int(s**0.5)
ax,bx=-b+ss,-b-ss
if ax%(a*2) or bx%(a*2):
 print('둘다틀렸근')
 exit(0)
axx,bxx=ax//(a*2),bx//(a*2)
if axx>1 and bxx>1 and (not axx&(axx-1)) and (not bxx&(bxx-1)): print('이수근')
else: print('정수근')