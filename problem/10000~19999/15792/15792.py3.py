from decimal import *
getcontext().prec=1234
a,b=map(Decimal,input().split())
print(a/b)