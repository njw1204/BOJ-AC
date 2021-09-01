cnt=[0]*10000001
tot=0
n=int(input())

for i in range(n):
    for j in map(int,input().split()):
        if j>0:
            cnt[j]+=1
            tot+=j
for i in range(9999999,0,-1):
    cnt[i]+=cnt[i+1]

if tot%2==0: need=tot//2
else: need=tot//2+1
cold=0

if need==0:
    print(0)
    exit(0)

for i in range(1,10000001):
    cold+=cnt[i]
    if cold>=need:
        print(i)
        exit(0)