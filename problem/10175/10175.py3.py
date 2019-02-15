for _ in range(int(input())):
    x,y=input().split()
    cnt=[0]*4
    name=["Bobcat","Coyote","Mountain Lion","Wolf"]
    val=[2,1,4,3]

    for i in y:
        for j in range(4):
            if i==name[j][0]:
                cnt[j]+=val[j]

    totFail=True
    for i in range(4):
        fail=False
        for j in range(4):
            if i!=j and cnt[i]<=cnt[j]:
                fail=True
                break
        if not fail:
            print("%s: The %s is the dominant species" % (x, name[i]))
            totFail=False
            break

    if totFail:
        print("%s: There is no dominant species" % x)