import sys
input=sys.stdin.readline
stack=[]
for i in range(int(input())):
 x=input()
 if x[:2]=='pu':
  stack.append(x.split()[1])
 if x[:2]=='to':
  if stack == []:
   print(-1)
  else:
   print(stack[-1])
 if x[:2]=='si':
  print(len(stack))
 if x[:2]=='em':
  if stack == []:
   print(1)
  else: print(0)
 if x[:2]=='po':
  if stack != []:
   print(stack.pop())
  else: print(-1)