def solve2():
    global ss,msl
    round=0
    for n,i in enumerate(ss):
        if i=="a": round+=1
        else:
            temp=0
            for j in range(1,msl-n+1):
                temp+=pow(26,j-1)*(ord(i)-ord("a"))
            round+=temp+1
    print(round)

round=0
succ=False
x=input()
if x!=x.strip(): exit(-1)

try:
    msl=x
    msl=int(msl)
    ss=input()
    if ss!=ss.strip(): exit(-1)
    for i in ss:
        if not (ord("a") <= ord(i) <= ord("z")):
            exit(-1)
    if len(ss)>msl: exit(-1)
except:
    while True: pass

succ=False
try:
    _=input()
except:
    succ=True

if not succ:
    exit(-1)

solve2()