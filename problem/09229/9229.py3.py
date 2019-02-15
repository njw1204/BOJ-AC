while True:
    li=[]
    while True:
        try:
            x=input()
            if x=="#": break
            li.append(x)
        except:
            exit(0)
    if not li: break
    result=True
    for i in range(len(li)-1):
        a,b=li[i],li[i+1]
        cnt=0
        if len(a)!=len(b):
            result=False
            break
        for j in range(len(a)):
            if a[j]!=b[j]: cnt+=1
        if cnt!=1:
            result=False
            break
    if result: print("Correct")
    else: print("Incorrect")