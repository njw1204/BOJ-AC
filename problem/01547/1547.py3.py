a=[1,0,0]
for i in range(int(input())):
 x,y=map(int,input().split())
 a[x-1],a[y-1]=a[y-1],a[x-1]
if a[0]: print(1)
if a[1]: print(2)
if a[2]: print(3)