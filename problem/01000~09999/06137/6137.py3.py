s=[]
for i in range(int(input())):
 s.append(input())
cnt=0
while s:
 flag=True
 for i in range(len(s)//2):
  if s[i]<s[-(i+1)]:
   print(s[0],end='')
   s.pop(0)
   flag=False
   break
  elif s[-(i+1)]<s[i]:
   print(s[-1],end='')
   s.pop()
   flag=False
   break
 if flag:
  print(s[-1],end='')
  s.pop()
 cnt+=1
 if cnt%80==0: print()