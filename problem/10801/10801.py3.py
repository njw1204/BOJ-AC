x,y=[*map(int,input().split())],[*map(int,input().split()),]
a,b=0,0
for i in range(10):
    if x[i]>y[i]: a+=1
    elif x[i]<y[i]: b+=1
if a>b: print('A')
elif a<b: print('B')
else: print('D')