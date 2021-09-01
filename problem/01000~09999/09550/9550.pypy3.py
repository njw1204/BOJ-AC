for _ in range(int(input())):
 n,k=map(int,input().split())
 print(sum(map(lambda e: int(e)//k,input().split())))