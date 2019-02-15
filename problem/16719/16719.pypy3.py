x=input()
used=[0]*len(x)
ns=""

for i in range(len(x)):
    nsli=list(ns)
    li=[]
    for j in range(len(x)):
        if not used[j]:
            cp=used[:]
            cp[j]=1
            tl=[]
            for k in range(len(x)):
                if cp[k]: tl.append(x[k])
            li.append(["".join(tl), j])
    tt=min(li)
    print(tt[0])
    used[tt[1]]=1