for i in range(int(input())):
    inp=input().split()
    c=int(inp[0])
    text=list(inp[1])
    for j in text: print(j*c,end='')
    print()