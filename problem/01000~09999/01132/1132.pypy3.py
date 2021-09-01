n=int(input())
x=[]
failZero=set()
summ={}
for i in range(n):
    x.append(input())
    zxc=1
    for j in x[-1][::-1]:
        summ[j]=summ.get(j,0)+zxc
        zxc*=10
    failZero.add(x[-1][0])

summ_list=[]
for k,v in summ.items():
    summ_list.append([k,v])
summ_list.sort(key=lambda x:x[1])

zeroPick=None
if len(summ_list)==10:
    summ_list2=[]
    for k,v in summ.items():
        if k not in failZero:
            summ_list2.append([k,v])
    summ_list2.sort(key=lambda x:x[1])
    zeroPick=summ_list2[0]
    summ_list.sort(key=lambda x:[x[0] != zeroPick[0], x[1]])

dd={}
orde=10-len(summ_list)
for k,v in summ_list:
    dd[k]=str(orde)
    orde+=1

ans=0
for round in x:
    for k,v in dd.items():
        round=round.replace(k,v)
    ans+=int(round)

print(ans)