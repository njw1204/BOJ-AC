n=int(input())
bits=[]
res=[]

if n==1:
    res.extend(["+", "/"])
    print(len(res))
    for i in res:
        print(end="[" + i + "] ")
    exit(0)

if n==2:
    res=["+"]
    print(len(res))
    for i in res:
        print(end="[" + i + "] ")
    exit(0)

if n==3:
    res=["+", "/", "+"]
    print(len(res))
    for i in res:
        print(end="[" + i + "] ")
    exit(0)

while n:
    bits.append(n%2)
    n//=2

bits=bits[::-1]
for i in bits:
    if i==1:
        res.append("*")
        res.append("+")
    else:
        res.append("*")
res.append("/")

print(len(res))
for i in res:
    print(end="[" + i + "] ")