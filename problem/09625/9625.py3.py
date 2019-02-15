A,B=1,0
for _ in range(int(input())):
 T=A
 A+=B
 B+=T
 A-=T
print(A,B)