import sys
from collections import deque
input=sys.stdin.readline
x=deque()
for _ in range(int(input())):
 t=input().split()
 if t[0]=='push_front': x.appendleft(t[1])
 if t[0]=='push_back': x.append(t[1])
 if t[0]=='pop_front':
  if x:
   print(x.popleft())
  else:
   print(-1)
 if t[0]=='pop_back':
  if x:
   print(x.pop())
  else:
   print(-1)
 if t[0]=='size': print(len(x))
 if t[0]=='empty': print(0 if x else 1)
 if t[0]=='front':
  if x:
   print(x[0])
  else:
   print(-1)
 if t[0]=='back':
  if x:
   print(x[-1])
  else:
   print(-1)
  