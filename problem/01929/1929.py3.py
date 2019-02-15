m,n=map(int,input().split())
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
for i in range(m,n+1):
    if sosu[i]: print(i)
