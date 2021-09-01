T=input()
success=True
stack=[]
stack2=[]
for i in T:
 if i=='(' or i=='[':
  stack.append(i)
  stack2.append('+(')
 elif i==')':
  if stack==[] or stack.pop()!='(':
   success=False
   break
  else: stack2.append(')*'+str(2))
 elif stack==[] or stack.pop()!='[':
  success=False
  break
 else: stack2.append(')*'+str(3))
if (not success) or stack!=[]:
 print(0)
 exit()
print(eval(''.join(stack2).replace('()','1')))