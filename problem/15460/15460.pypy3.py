n=int(input())
x=[*map(int,input().split())]


ansl,ansr=-1,n
sum=[0]*n
minn=[0]*n
sum[n-1]=x[n-1]
minn[n-1]=x[n-1]

for i in range(n-2,0,-1):
    sum[i]=sum[i+1]+x[i]
    minn[i]=min(minn[i+1],x[i])
    nowScore=sum[i]-minn[i]

    if nowScore*ansr>ansl*(n-i-1):
        ansl,ansr=nowScore,n-i-1
        ks=[i]
    elif nowScore*ansr==ansl*(n-i-1):
        ks.append(i)

ks.sort()
for i in ks:
    print(i)