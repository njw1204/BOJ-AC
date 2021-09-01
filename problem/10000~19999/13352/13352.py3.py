import sys,random,math
input=sys.stdin.readline

n=int(input())
if n<=4:
    print("success")
    exit(0)
x=[]
for i in range(n):
    x.append([*map(int,input().split())])

for _ in range(50):
    a,b=random.sample(x,2)
    xdiff,ydiff=a[0]-b[0],a[1]-b[1]
    if xdiff>0 and ydiff<0:
        sign=-1
    elif xdiff<0 and ydiff>0:
        sign=-1
    else:
        sign=1
    xdiff,ydiff=abs(xdiff),abs(ydiff)
    dx,dy=xdiff//math.gcd(xdiff,ydiff),ydiff//math.gcd(xdiff,ydiff)
    dx*=sign
    
    others=[]
    for j in range(n):
        if x[j]==a or x[j]==b: continue
        p=x[j]

        xdiff,ydiff=a[0]-p[0],a[1]-p[1]
        if xdiff>0 and ydiff<0:
            sign=-1
        elif xdiff<0 and ydiff>0:
            sign=-1
        else:
            sign=1
        xdiff,ydiff=abs(xdiff),abs(ydiff)
        tdx,tdy=xdiff//math.gcd(xdiff,ydiff),ydiff//math.gcd(xdiff,ydiff)
        tdx*=sign

        if dx!=tdx or dy!=tdy:
            others.append(p)

    if len(others)<=2:
        print("success")
        exit(0)
    else:
        succ=True
        a,b=others[:2]
        xdiff,ydiff=a[0]-b[0],a[1]-b[1]
        if xdiff>0 and ydiff<0:
            sign=-1
        elif xdiff<0 and ydiff>0:
            sign=-1
        else:
            sign=1
        xdiff,ydiff=abs(xdiff),abs(ydiff)
        dx,dy=xdiff//math.gcd(xdiff,ydiff),ydiff//math.gcd(xdiff,ydiff)
        dx*=sign

        for j in others[2:]:
            xdiff,ydiff=a[0]-j[0],a[1]-j[1]
            if xdiff>0 and ydiff<0:
                sign=-1
            elif xdiff<0 and ydiff>0:
                sign=-1
            else:
                sign=1
            xdiff,ydiff=abs(xdiff),abs(ydiff)
            tdx,tdy=xdiff//math.gcd(xdiff,ydiff),ydiff//math.gcd(xdiff,ydiff)
            tdx*=sign
            if dx!=tdx or dy!=tdy:
                succ=False
                break

        if succ:
            print("success")
            exit(0)

print("failure")