n=int(input())
i,j=2,2
a=n*2
while i<=n:
 a+=(n//i)*(j*2-j)
 i*=2
 j*=2
print(a)