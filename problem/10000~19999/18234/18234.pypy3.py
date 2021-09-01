import sys
input=sys.stdin.readline

n,t=map(int,input().split())
arr=[]
for i in range(n):
    w,p=map(int,input().split())
    arr.append([w,p])
arr.sort(key=lambda x:x[1])

answer=0
day=t-n
for w,p in arr:
    answer+=w+p*day
    day+=1
print(answer)