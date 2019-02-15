for _ in range(int(input())):
 T=input()
 P,F=False,False
 X=[0]*128
 for i in range(len(T)):
  if P:
   P=False
   continue
  c=T[i]
  X[ord(c)]+=1
  if X[ord(c)]%3==0:
   if i<len(T)-1 and T[i]==T[i+1]: P=True
   else:
    print('FAKE')
    F=True
    break
 if not F: print('OK')