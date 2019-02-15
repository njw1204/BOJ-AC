for _ in range(int(input())):
    x,y=input().split("=")
    if eval(x)==int(y):
        print("Case %d: YES" % (_ + 1))
    else:
        print("Case %d: NO" % (_ + 1))