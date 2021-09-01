import sys
input=sys.stdin.readline

n=int(input())
a=[*map(int,input().split())]
q=int(input())
ad=[0]*(n-1)
query=[0]*q
result=[0]*q

for i in range(q):
    x,y=map(int,input().split())
    query[i]=[x-1,y,i]

query.sort()

ns=0
for i in range(q):
    nowQuery=query[i]
    if i==0:
        if nowQuery[0]==nowQuery[1]:
            result[i]=[nowQuery[2],0]
        else:
            ns=sum(a[nowQuery[0]:nowQuery[1]])
            result[i]=[nowQuery[2],ns]
    else:
        if nowQuery[0]==query[i-1][0]:
            ns+=sum(a[query[i-1][1]:nowQuery[1]])
        else:
            ns=sum(a[nowQuery[0]:nowQuery[1]])
        result[i]=[nowQuery[2],ns]

result.sort()

for i in result:
    print(i[1])