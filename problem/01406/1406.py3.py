import sys

T=list(input())
T2=[]
lenT,lenT2=len(T),0
cur=lenT

for _ in range(int(input())):
 c=sys.stdin.readline()
 if c[0]=='L':
  if cur:
   T2.append(T.pop())
   lenT-=1
   lenT2+=1
   cur-=1
 elif c[0]=='D':
  if cur<lenT+lenT2:
   T.append(T2.pop())
   lenT+=1
   lenT2-=1
   cur+=1
 elif c[0]=='B':
  if cur:
   T.pop()
   cur-=1
   lenT-=1
 else:
  T.append(c.split()[1])
  cur+=1
  lenT+=1
print(''.join(T)+''.join(reversed(T2)))