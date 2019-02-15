for t in range(int(input())):
    x,y=map(int,input().split())
    print("Scenario #%d:"%(t+1))
    print((y-x+1)*(x+y)//2)
    print()