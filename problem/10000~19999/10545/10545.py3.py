aa=[*map(int,input().split())]
a=[]
for i in range(1,10): a.append(aa.index(i)+1)
t=input()
d={2:'abc',3:'def',4:'ghi',5:'jkl',6:'mno',7:'pqrs',8:'tuv',9:'wxyz'}
for i in range(len(t)):
 if i>0:
  for j in range(2,10):
   if t[i] in d[j]:
    if t[i-1] in d[j]: print('#',end='')
    print(str(a[j-1])*(d[j].find(t[i])+1),end='')
    break
 else:
  for j in range(2,10):
   if t[i] in d[j]:
    print(str(a[j-1])*(d[j].find(t[i])+1),end='')
    break