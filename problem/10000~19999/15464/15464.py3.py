n=int(input())
x=[*map(int,input().split())]
t=input().split()

mov=[0]*n
for i in range(n):
    mov[x[i]-1]=i

for i in range(3):
    tt=[0]*n
    for j in range(n):
        tt[mov[j]]=t[j]
    t=tt

for i in t:
    print(i)