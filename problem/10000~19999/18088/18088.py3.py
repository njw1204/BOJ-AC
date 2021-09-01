N=int(input())
v=[*map(int,input().split())]
ba=ba2=-1
last=-1
dec_start=False

for n,i in enumerate(v):
    if i>=last:
        if i>last:
            if not dec_start:
                ba=n
            else:
                ba2=n-1
                break
    else:
        dec_start=True
    last=i

if not dec_start:
    print("1 1")
    exit(0)

if ba>-1 and ba2==-1:
    ba2=N-1

revv=v[ba:ba2+1]
revv=revv[::-1]

for i in range(len(revv)):
    v[ba+i]=revv[i]

for i in range(1,len(v)):
    if v[i]<v[i-1]:
        print("impossible")
        exit(0)

print(ba+1,ba2+1)