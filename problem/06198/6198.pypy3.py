ans=0
stack=[]
last=99999999999
for i in range(int(input())):
 x=int(input())
 if x>=last:
  while stack!=[]:
   temp=stack.pop()
   if x<temp:
    stack.append(temp)
    break
 ans+=len(stack)
 stack.append(x)
 last=x
print(ans)