x,y=map(int,input().split())
if y==0: print(x)
else: print((x+(10**(y-1)*5))//(10**y)*(10**y))