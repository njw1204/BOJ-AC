x=list(input())
minus=False
for i in range(len(x)):
 if x[i]=='+':
  if minus: x[i]='-'
 elif x[i]=='-': minus=True
temp=[]
result=0
state=0
x.append('+')
for i in x:
 if ord('0')<=ord(i)<=ord('9'): temp.append(i)
 else:
  if state==0: result=int(''.join(temp))
  elif state==1: result+=int(''.join(temp))
  else: result-=int(''.join(temp))
  state=eval(i+'1')
  temp=[]
print(result)