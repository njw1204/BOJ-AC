a,b,d=map(int,input().split())
sosu=[True]*(b+5)
sosu[1],sosu[2]=False,True
i=2
while i*i<=b:
    if sosu[i]==False:
        i+=1
        continue
    j=i*i
    while j<=b:
        sosu[j]=False
        j+=i
    i+=1
acs=0
for i in range(a,b+1):
    if not sosu[i]: continue
    chk=False
    while i>0:
        if i%10==d:
            chk=True
            break
        i//=10
    if chk: acs+=1
print(acs)