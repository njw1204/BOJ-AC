x=input()
a=0
for i in x:
 if a==0 and i=='U': a+=1
 elif a==1 and i=='C': a+=1
 elif a==2 and i=='P': a+=1
 elif a==3 and i=='C': a+=1
if a==4: print ('I love UCPC')
else: print ('I hate UCPC')