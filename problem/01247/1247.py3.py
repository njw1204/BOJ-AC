import sys
input=sys.stdin.readline
for i in range(3):
 s=0
 for j in range(int(input())):
  s+=int(input())
 if s>0: print('+')
 elif s==0: print(0)
 else: print('-')