for _ in range(int(input())):
 x,y=map(int,input().split())
 if x<12 or y<4: print(-1)
 else: print(11*y+4)