for i in input():
 if not i.isalpha():
   print(i,end='')
   continue
 t=chr(ord('A')+(ord(i.upper())-ord('A')+13)%26)
 if i.islower(): print(t.lower(),end='')
 else: print(t,end='')