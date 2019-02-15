def 소인수(n):
 i,c=2,0
 while n>1:
  if n%i==0: c+=1
  while n%i==0: n//=i
  i+=1
 if c==0: c=1
 return c

n=input()
if int(n)>5 and sum(map(int,list(n)))%2: 이면수=True
else: 이면수=False
if int(n)==2 or int(n)==4 or 소인수(int(n))%2==0: 임현수=True
else: 임현수=False

if 이면수 and not 임현수: a=1
if 임현수 and not 이면수: a=2
if not (이면수 or 임현수): a=3
if 이면수 and 임현수: a=4
print(a)