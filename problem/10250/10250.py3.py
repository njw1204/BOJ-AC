for _ in range(int(input())):
 H,W,N=map(int,input().split())
 X=(N-1)//H+1
 Y=(N-1)%H+1
 print('%d%02d'%(Y,X))