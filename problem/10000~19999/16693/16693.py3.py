import math
x,y=map(int,input().split())
r,z=map(int,input().split())
if x/y>r*r*math.pi/z:
 print("Slice of pizza")
else:
 print("Whole pizza")