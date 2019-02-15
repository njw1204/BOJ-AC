stack,stack2=[],[]
for i in input():
 if i in '+-':
  while stack2!=[] and stack2[-1]!='(':
   stack.append(stack2.pop())
  stack2.append(i)
 elif i in '*/':
  while stack2!=[] and stack2[-1] not in '(+-':
   stack.append(stack2.pop())
  stack2.append(i)
 elif i=='(':
  stack2.append(i)
 elif i==')':
  while stack2[-1]!='(':
   stack.append(stack2.pop())
  stack2.pop()
 else: stack.append(i)

while stack2!=[]: stack.append(stack2.pop())
print(''.join(stack))