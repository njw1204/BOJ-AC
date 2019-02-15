E,S,M=map(int,input().split())
EMAX,SMAX,MMAX=15,28,19
A,B,C=0,0,0
if (1,1,1)==(E,S,M):
 print(1)
 exit()
for i in range(2,7981):
 A+=1; B+=1; C+=1
 A%=EMAX; B%=SMAX; C%=MMAX
 if (A+1,B+1,C+1)==(E,S,M):
  print(i)
  exit()