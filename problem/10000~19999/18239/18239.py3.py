n,k=map(int,input().split())
if n-k>=2 and k>=2:
    print("YES")
    print("swap", k, k + 1)
    print("reverse", 1, k)
    print("reverse", k + 1, n)
    print("swap", 1, n)
    print("reverse", 1, n)
else:
    if n==2:
        print("YES")
        for _ in range(5):
            print("swap 1 2")
    elif k==1:
        if n==3:
            print("NO")
        elif n==4:
            print("YES")
            print("swap 3 4")
            print("swap 1 2")
            print("swap 2 3")
            print("swap 3 4")
            print("swap 2 3")
        else:
            print("YES")
            print("reverse", 3, n - 1)
            print("swap", 2, n)
            print("swap", n - 1, n)
            print("swap", n - 1, n)
            print("reverse", 1, n)
    elif n-k==1:
        if n==3:
            print("NO")
        else:
            print("YES")
            print("swap", n - 1, n)
            print("reverse", 1, k)
            print("reverse", 2, n - 1)
            print("reverse", 1, n)
            print("reverse", 1, n)