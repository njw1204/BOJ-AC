p,k=map(int,input().split())
sosu=[True]*(k+1)
sosu[0]=sosu[1]=False
i=2
while i*i<=k:
    if sosu[i]==False:
        i+=1
        continue
    j=i*i
    while j<=k:
        sosu[j]=False
        j+=i
    i+=1

for i in range(2,k):
    if sosu[i] and p%i==0:
        print("BAD", i)
        exit(0)

print("GOOD")