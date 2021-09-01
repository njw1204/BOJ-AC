import sys
t=sys.stdin.readline
for i in range(int(t())):
 x=int(t())
 print(+(x&x-1==0))