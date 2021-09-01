from collections import deque
n,x=int(input()),deque()
for i in range(1,n+1): x.append(i)
while len(x)>1:
 print(x.popleft(),end=' ')
 if len(x)==1: break
 x.append(x.popleft())
print(x.pop())