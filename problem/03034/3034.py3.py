N,W,H=map(int,input().split())
G=W*W+H*H
for _ in range(N):
 if int(input())**2<=G: print('DA')
 else: print('NE')