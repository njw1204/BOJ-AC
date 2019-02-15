s=[]
for i in input():
 if ord('0')<=ord(i)<=ord('9'):
  s.append(i)
 else:
  a,b=s.pop(),s.pop()
  if i=='/': i+=i
  s.append(str(eval(b+i+a)))
print(s.pop())