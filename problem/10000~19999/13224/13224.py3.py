a,b,c=1,0,0
for i in input():
    if i=="A":
        a,b=b,a
    elif i=="B":
        b,c=c,b
    else:
        a,c=c,a

if a: print(1)
elif b: print(2)
else: print(3)