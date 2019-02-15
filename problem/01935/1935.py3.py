n=int(input())
T=input()
alnum=dict()
for i in range(n):
 alnum[chr(ord('A')+i)]=int(input())
stack=[]
for i in T:
 if i in '*/+-':
  a,b=stack.pop(),stack.pop()
  stack.append(eval(str(b)+i+str(a)))
 else: stack.append(alnum[i])
print('%.2f'%stack[0])