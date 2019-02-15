x=[[0]*26 for i in range(26)]
for i in range(int(input())):
 a,_,b=input().split()
 x[ord(a)-ord('a')][ord(b)-ord('a')]=1
for i in range(26):
 for j in range(26):
  for k in range(26):
   if x[j][i] and x[i][k]:
    x[j][k]=1
for i in range(int(input())):
 a,_,b=input().split()
 if x[ord(a)-ord('a')][ord(b)-ord('a')]:
  print('T')
 else:
  print('F')