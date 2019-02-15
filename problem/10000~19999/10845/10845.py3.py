import sys
input=sys.stdin.readline
queue=[]
pos=0
for i in range(int(input())):
 x=input()
 if x[:2]=='pu':
  queue.append(x.split()[1])
 if x[:2]=='fr':
  if pos==len(queue):
   print(-1)
  else:
   print(queue[pos])
 if x[:2]=='ba':
  if pos==len(queue):
   print(-1)
  else:
   print(queue[-1])
 if x[:2]=='si':
  print(len(queue)-pos)
 if x[:2]=='em':
  if pos==len(queue):
   print(1)
  else: print(0)
 if x[:2]=='po':
  if pos!=len(queue):
   print(queue[pos])
   pos+=1
  else: print(-1)