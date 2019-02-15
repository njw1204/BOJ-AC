a=[*map(int,input().split())]
b=[*map(int,input().split())]
c=[*map(int,input().split())]
x=0

for i in range(-1000,1001):
    for j in range(-1000,1001):
        if not (c[0]<=i<c[2]) or not (c[1]<=j<c[3]):
            if (a[0]<=i<a[2]) and (a[1]<=j<a[3]):
                x+=1
            elif (b[0]<=i<b[2]) and (b[1]<=j<b[3]):
                x+=1

print(x)