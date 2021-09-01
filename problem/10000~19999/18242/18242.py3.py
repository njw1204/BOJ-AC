import re
n,m=map(int,input().split())
s=False
lp=-1

for i in range(n):
    x=input()
    if re.search(r"#\.#", x):
        if s:
            print("DOWN")
            break
        else:
            print("UP")
            break

    if not s:
        lp=x.find("#")
        if lp>=0:
            s=True
    else:
        if x.count("#")==1:
            if x[lp]=="#":
                print("RIGHT")
                break
            else:
                print("LEFT")
                break