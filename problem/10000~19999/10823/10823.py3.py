x=0
xx=''
try:
    while True:
        xx+=input()
except:
    xx=xx.split(',')
    for i in xx:
        if i: x+=int(i)
    print(x)