ans=0
x1,y1,r1=map(int,input().split())
x2,y2,r2=map(int,input().split())
x3,y3,r3=map(int,input().split())
for i in range(23001):
  for j in range(23001):
    if (x1-i/230+0.0022)**2+(y1-j/230+0.0022)**2<=r1*r1: ans+=1
    elif (x2-i/230+0.0022)**2+(y2-j/230+0.0022)**2<=r2*r2: ans+=1
    elif (x3-i/230+0.0022)**2+(y3-j/230+0.0022)**2<=r3*r3: ans+=1
print(ans/52900)