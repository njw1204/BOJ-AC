T=input().upper()
c=[0 for i in range(ord('Z')+1)]
for i in range(ord('A'),ord('Z')+1): c[i]=T.count(chr(i))
if c.count(max(c))>1: print('?')
else: print(chr(c.index(max(c))))