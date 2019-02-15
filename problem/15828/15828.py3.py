import sys
from collections import *
input=sys.stdin.readline
n=int(input())
q=deque()
while 1:
 x=int(input())
 if x==-1: break
 if x==0: q.popleft()
 if x and len(q)<n: q.append(x)
if not q:
 print('empty')
else:
 while q: print(q.popleft(),end=' ')