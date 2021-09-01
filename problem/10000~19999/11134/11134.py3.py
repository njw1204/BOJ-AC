for _ in range(int(input())):
 x,y=map(int,input().split())
 print(x//y if x%y==0 else x//y+1)