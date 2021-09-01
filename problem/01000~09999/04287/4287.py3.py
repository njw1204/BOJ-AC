while True:
    x=input().split()
    if x[0]=="#": break

    result=[]
    for i in range(len(x[0])):
        diff=ord(x[1][i])-ord(x[0][i])
        if diff<0: diff+=26

        base=ord(x[2][i])-ord('a')
        after=(base+diff)%26
        result.append(chr(ord('a')+after))

    print(x[0],x[1],x[2],"".join(result))