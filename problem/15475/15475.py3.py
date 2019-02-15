input()
a=c=0
for i in map(int,input().split()):
 if i==1: c+=1
 else: c=0
 a=max(a,c+1)
print(a)