aatk,alife=map(int,input().split())
batk,blife=map(int,input().split())
adie=bdie=False
while alife>0 and blife>0:
 alife-=batk
 blife-=aatk
 if alife<=0: adie=True
 if blife<=0: bdie=True
if adie and bdie:
 print('DRAW')
elif bdie:
 print('PLAYER A')
else:
 print('PLAYER B')