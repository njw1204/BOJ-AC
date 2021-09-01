xx=''
try:
    while True:
        xx+=input()
except:
    print(sum([int(i) for i in xx.split(',') if i]))