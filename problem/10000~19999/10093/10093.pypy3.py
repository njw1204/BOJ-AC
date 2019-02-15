a,b=sorted(map(int,input().split()))
if abs(a-b)<=1:
 print(0)
 exit()
print(b-a-1)
for i in range(a+1,b):
 print(i,end=" ")