def distance(a,b):
    return ((a[0]-b[0])**2+(a[1]-b[1])**2)**0.5

def ccw(a,b,c):
    temp = a[0]*b[1] + b[0]*c[1] + c[0]*a[1]
    temp = temp - b[0]*a[1] - c[0]*b[1] - a[0]*c[1]
    return temp

x=[*map(int,input().split())]
a=x[:2]
b=x[2:4]
c=x[4:]

if ccw(a,b,c) == 0:
    print(-1)
    exit(0)

result=[]
result.append(distance(a,b)+distance(b,c))
result.append(distance(a,c)+distance(b,c))
result.append(distance(a,b)+distance(a,c))
print((max(result)-min(result))*2)