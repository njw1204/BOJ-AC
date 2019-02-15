from collections import deque
n=int(input())
q=deque(map(int,input().split()))
x=1
s=[]
while s or q:
 if q and q[0]==x:
  q.popleft()
  x+=1
 elif s and s[-1]==x:
  s.pop()
  x+=1
 elif q: s.append(q.popleft())
 else:
  print('Sad')
  exit()
print('Nice')