A,B=map(int,input().split())
print(abs((A-1)%4-(B-1)%4)+abs((A-1)//4-(B-1)//4))