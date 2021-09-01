import sys

d,k=map(int,input().split())
if d==3:
    print(1)
    print(k-1)
    sys.exit(0)

fib=[0]*40
fib[1]=fib[2]=1
for i in range(3,40):
    fib[i]=fib[i-1]+fib[i-2]

ac,bc=fib[d-2],fib[d-1]

for i in range(1,100000):
    temp_k=k-ac*i
    if temp_k>0 and temp_k%bc==0:
        temp_k//=bc
        if temp_k>=i:
            print(i)
            print(temp_k)
            sys.exit(0)