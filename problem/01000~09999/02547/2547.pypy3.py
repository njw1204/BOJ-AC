import sys
input=sys.stdin.readline
for _ in range(int(input())):
    input()
    c=int(input())
    x=sum([int(input()) for i in range(c)])
    if x%c==0: print("YES")
    else: print("NO")