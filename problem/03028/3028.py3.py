A,B,C=1,0,0
for i in input():
 if i=='A': A,B=B,A
 if i=='B': B,C=C,B
 if i=='C': A,C=C,A
print(1 if A==1 else 2 if B==1 else 3)