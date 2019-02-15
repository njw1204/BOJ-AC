import sys
N=int(input())
S=[0]*100001
for i in range(N):
 S[int(sys.stdin.readline().replace('.',''))]+=1
C=0
for i in range(100001):
 if S[i]:
  if C+S[i]<=7:
   exec("print('%.3f'%(i/1000));"*S[i])
   C+=S[i]
  else:
   exec("print('%.3f'%(i/1000));"*(7-C))
   break