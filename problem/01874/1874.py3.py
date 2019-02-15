import sys
n,lst,max_top=int(input()),[0],0
result=''
for i in range(n):
 x=int(sys.stdin.readline())
 if x>lst[-1]:
  for j in range(max_top+1,x+1):
   result+='+'+'\n'
   lst.append(j)
  result+='-'+'\n'
  lst.pop()
 else:
  if lst.pop()==x: result+='-'+'\n'
  else:
   print('NO')
   exit()
 max_top=max(max_top,x)
print(result)