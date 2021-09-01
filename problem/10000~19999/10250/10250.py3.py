for _ in range(int(input())):
    h,w,n=map(int,input().split())
    no=(n-1)//h+1
    ch=(n-1)%h+1
    print("%d%02d" % (ch,no))