while True:
    try:
        a=0
        n,m=map(int,input().split())
        for i in range(n,m+1):
            s=list(str(i))
            if len(s)==len(set(s)):a+=1
        print(a)
    except:
        exit(0)