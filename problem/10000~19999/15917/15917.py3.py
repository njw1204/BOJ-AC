import sys
input=sys.stdin.readline
for i in range(int(input())):
 x=int(input())
 if x&(x-1): print(0)
 else: print(1)