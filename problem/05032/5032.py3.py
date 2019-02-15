A,B,C=map(int,input().split())
A+=B
ANS=0
while A>=C:
 ANS+=A//C
 A=A//C+A%C
print(ANS)