x=list(input())
if 'x' not in x:
 print(0)
 exit()
x=''.join(x[:x.index('x')])
if x=='-': print(-1)
elif x=='+' or x=='': print(1)
else: print(eval(x))