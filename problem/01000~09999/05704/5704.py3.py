while 1:
 T=input().replace(' ','')
 D={}
 if T=='*': exit()
 for i in T: D[i]=1
 print('Y' if len(D)==26 else 'N')