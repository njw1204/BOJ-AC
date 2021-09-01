n=int(input())
x,r=1,1
for i in range(5000000):
    if x%n==0:
        print(r)
        exit(0)
    x%=n
    x=x*10+1
    r+=1
print(-1)