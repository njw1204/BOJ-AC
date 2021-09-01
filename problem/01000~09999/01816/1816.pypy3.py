n=int(input())

sosu=[True]*(1000005)
sosu[1],sosu[2]=False,True
i=2
while i*i<=1000000:
    if sosu[i]==False:
        i+=1
        continue
    j=i*i
    while j<=1000000:
        sosu[j]=False
        j+=i
    i+=1
sosus=[]

for i in range(1,1000001):
    if sosu[i]: sosus.append(i)

for i in range(n):
    x=int(input())
    succ=True
    for j in sosus:
        if x%j==0:
            print("NO")
            succ=False
            break
    if succ: print("YES")