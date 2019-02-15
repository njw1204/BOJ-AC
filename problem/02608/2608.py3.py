rodict = {
    'I' : 1,
    'V' : 5,
    'X' : 10,
    'L' : 50,
    'C' : 100,
    'D' : 500,
    'M' : 1000,
    'IV' : 4,
    'IX' : 9,
    'XL' : 40,
    'XC' : 90,
    'CD' : 400,
    'CM' : 900
}


def get(n):
    for k,v in rodict.items():
        if len(k)==1: continue
        n=n.replace(k,' ' + str(v) + ' ')
    pred=n.split()
    ret=0
    for i in pred:
        if i[0] not in rodict: ret+=int(i)
        else:
            for j in i: ret+=rodict[j]
    return ret


def set(n):
    result=''
    sorted_ro=sorted(rodict.items(),key=lambda x:x[1],reverse=True)
    for k,v in sorted_ro:
        while n>=v:
            n-=v
            result+=k
    return result


x,y=input(),input()
z=get(x)+get(y)
print(z)
print(set(z))