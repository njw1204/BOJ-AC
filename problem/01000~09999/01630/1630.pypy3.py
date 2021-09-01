n=1000000
sosu=[True]*(n+5)
sosu[1],sosu[2]=False,True
i=2
while i*i<=n:
    if sosu[i]==False:
        i+=1
        continue
    j=i*i
    while j<=n:
        sosu[j]=False
        j+=i
    i+=1

sosu_parsed=[]
for i in range(1,1000001):
    if sosu[i]: sosu_parsed.append(i)

div_cnt=[0]*(n+5)
ii=int(input())

if ii>380000:
    print(0)
    exit(0)

for i in range(2,ii+1):
    val=i

    if sosu[val]:
        div_cnt[val]=max(div_cnt[val],1)
        continue

    div_temp_cnt=dict()

    for j in sosu_parsed:
        while val%j==0:
            div_temp_cnt[j]=div_temp_cnt.get(j,0)+1
            val//=j
        if val==1: break

    for k,v in div_temp_cnt.items():
        div_cnt[k]=max(div_cnt[k],v)

ans=1
mod=987654321
for i in range(2,1000001):
    if div_cnt[i]:
        ans*=pow(i,div_cnt[i],mod)
        ans%=mod

print(ans)