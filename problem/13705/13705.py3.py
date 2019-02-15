import math
from decimal import *
getcontext().prec=60

pi = Decimal("3.14159265358979323846264338327950288419716939937510")

def gen_den():
    d = 1
    f = 1
    while(1):
        yield f
        d = d + 1
        f = f * d
    return

def gen_num(x):
    n = x
    while(1):
        yield n
        n *= x
    return

def gen_sign():
    while(1):
        yield 1
        yield -1
        yield -1
        yield 1
    return

def sincos(x):
    x = divmod(x, 2 * pi)[1]
    den = gen_den()
    num = gen_num(x)
    sign = gen_sign()

    s = 0
    c = 1
    i = 1
    done_s = False; done_c = False

    while(not done_s and not done_c):
        new_s = s + sign.__next__() * num.__next__()/ den.__next__()
        new_c = c + sign.__next__() * num.__next__() / den.__next__()
        if (new_c - c == 0): done_c = True
        if (new_s - s == 0): done_s = True
        c = new_c
        s = new_s
        i = i + 2
    return (s, c)

a,b,c=map(Decimal,input().split())
x,t=Decimal(0),Decimal(10**9)
deter=Decimal(1e-30)
while True:
 t=(c-b*sincos(x)[0])/a
 if abs(t-x)<deter: break
 x=t
print(x.quantize(Decimal("1.000000")))