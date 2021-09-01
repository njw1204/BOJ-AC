n,m=map(int,input().split())
cnt=[0]*10
for i in range(n,m+1):
    while i>0:
        cnt[i%10]+=1
        i//=10
for i in cnt:
    print(i,end=" ")