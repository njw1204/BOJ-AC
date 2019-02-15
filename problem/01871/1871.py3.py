W=lambda A:(ord(A[0])-ord('A'))*26*26+(ord(A[1])-ord('A'))*26+(ord(A[2])-ord('A'))
for _ in range(int(input())):
  A,B=input().split('-')
  if abs(W(A)-int(B))<=100: print('nice')
  else: print('not nice')