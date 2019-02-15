input()
x,c=[],'W'
for i in input():
 if i!=c:
  c=i
  x.append(i)
print(len(x)//2)