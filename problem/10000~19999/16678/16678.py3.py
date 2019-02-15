import sys
input=sys.stdin.readline
n=int(input())
x=[]
for i in range(n): x.append(int(input()))
x.sort()
d,a=0,0
for i in x:
 if d>=i: continue
 d+=1
 if i>d: a+=i-d
print(a) 