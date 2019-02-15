x=input()
for i in range(10):
    x=x.replace(str(i),'')
if x.find(input())!=-1: print(1)
else: print(0)