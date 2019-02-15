a,b,c,d=1,0,0,2
for ch in input():
 if ch=='A': a,b=b,a
 elif ch=='B': a,c=c,a
 elif ch=='C': a,d=d,a
 elif ch=='D': b,c=c,b
 elif ch=='E': b,d=d,b
 else: c,d=d,c
for j in range(1,3):
  for k,i in enumerate((a,b,c,d)):
    if i==j: print(k+1)