c,k,p=map(int,input().split())
a=0
for i in range(c+1):
 a+=i*k+i*i*p
print(a)