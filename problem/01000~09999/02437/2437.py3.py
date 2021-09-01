input()
x=sorted(map(int,input().split()))
a=0
for i in x:
  if i>a+1: break
  a+=i
print(a+1)
