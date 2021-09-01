d,p,q=map(int,input().split())
p,q=max(p,q),min(p,q)
prod=0

if d//p <= 1000000:
    ans=10**10
    while True:
        qprod = 0
        dremain = d - p*prod
        if dremain > 0:
            qprod = dremain // q
            if dremain % q > 0:
                qprod += 1
        ans=min(ans, prod*p + qprod*q)
        prod+=1

        if qprod == 0: break

    print(ans)
    exit(0)

prod = d // p
dremain = d - p*prod
start_i = prod + 1 if dremain else prod
ans=10**10
for i in range(start_i, start_i - 1000000, -1):
    if i<0: break
    prod = i
    qprod = 0
    dremain = d - p*prod
    if dremain > 0:
        qprod = dremain // q
        if dremain % q > 0:
            qprod += 1
    ans=min(ans, prod*p + qprod*q)

print(ans)