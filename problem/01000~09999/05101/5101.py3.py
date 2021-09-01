while True:
    x,y,z=map(int,input().split())
    if x==y==z==0: break
    z-=x
    if z%y==0 and z//y+1>0: print(z//y+1)
    else: print("X")