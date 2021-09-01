import sys
input=sys.stdin.readline
for _ in range(int(input())):
    a,b,c=map(int,input().split())
    sol1 = a**2 + (b+c)**2
    sol2 = b**2 + (a+c)**2
    sol3 = c**2 + (a+b)**2
    print(min(sol1,sol2,sol3))