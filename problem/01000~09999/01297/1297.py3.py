import math
D,RH,RW=map(int,input().split())
A=D/math.sqrt(RH*RH+RW*RW)
H,W=map(int,(RH*A,RW*A))
print(H,W)