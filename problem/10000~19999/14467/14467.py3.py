n=int(input())
di=dict()
a=0

for i in range(n):
    x,y=map(int,input().split())
    if x in di and di[x]!=y: a+=1
    di[x]=y

print(a)