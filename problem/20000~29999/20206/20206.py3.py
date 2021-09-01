def f(x):
    global a, b, c
    return (-a * x - c) / b

a, b, c = map(int, input().split())
x1, x2, y1, y2 = map(int, input().split())

if b == 0:
    if x1 < (-c / a) < x2:
        print('Poor')
    else:
        print('Lucky')
    exit(0)

if f(x1) >= y2 and f(x2) < y2:
    print('Poor')
elif f(x1) <= y1 and f(x2) > y1:
    print('Poor')
elif y1 < f(x1) < y2:
    print('Poor')
else:
    print('Lucky')