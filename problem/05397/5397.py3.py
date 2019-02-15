from collections import deque
for _ in range(int(input())):
  cus=0
  l,r=deque(),deque()
  for i in input():
    if i=='<':
      cus=max(cus-1,0)
      if l: r.appendleft(l.pop())
    elif i=='>':
      cus=min(cus+1,len(l)+len(r))
      if r: l.append(r.popleft())
    elif i=='-':
      cus=max(cus-1,0)
      if l: l.pop()
    else:
      cus+=1
      l.append(i)
  print(''.join(l)+''.join(r))