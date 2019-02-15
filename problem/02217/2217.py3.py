import sys
input=sys.stdin.readline

n=int(input())
x=[0]*n
for i in range(n): x[i]=int(input())
x.sort(reverse=True)
k,a=0,0
for i in x:
 k+=1
 if i*k>a: a=i*k
print(a)