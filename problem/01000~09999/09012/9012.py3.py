import sys
input=sys.stdin.readline

for _ in range(int(input())):
 T=input().rstrip('\n')
 level=0
 fail=False
 for i in T:
  if i=='(': level+=1
  else: level-=1
  if level<0:
   fail=True
   break
 if fail or level!=0:
  print('NO')
 else: print('YES')