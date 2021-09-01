import math
L,A,B,C,D=int(input()),int(input()),int(input()),int(input()),int(input())
print(L-max(math.ceil(A/C),math.ceil(B/D)))