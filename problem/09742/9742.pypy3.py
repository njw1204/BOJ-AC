import itertools
while True:
    try:
        x,y=input().split()
        x,y=list(x),int(y)
        try:
            p=itertools.permutations(x)
            for i in range(y-1): p.__next__()
            print("".join(x),y,"=","".join(p.__next__()))
        except:
            print("".join(x),y,"=","No permutation")
            continue
    except:
        exit(0)