N = int(input())
if N==1: print(1)
else:
  N-=1
  R=0
  ANS=1
  while R<N:
    ANS+=1
    R+=6*(ANS-1)
  print(ANS)