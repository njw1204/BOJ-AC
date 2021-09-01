for i in range(int(input())):
 x,y=input().split()
 print(bin(int(x,2)+int(y,2))[2:])