import sys
input=sys.stdin.readline

while True:
    x=[*map(int,input().split())]
    if x[0]==0: break

    ans=0
    while len(set(x))>1:
        new_x=[abs(x[0]-x[1]),abs(x[1]-x[2]),abs(x[2]-x[3]),abs(x[3]-x[0])]
        x=new_x
        ans+=1
    print(ans)