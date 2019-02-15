import sys
input=sys.stdin.readline
a,b=0,0
for i in range(int(input())):
 A,B=map(int,input().split())
 if A>B: a+=1
 if B>A: b+=1
print(a,b)