import sys
input=sys.stdin.readline

for _ in range(int(input())):
    p,m,f,c=map(int,input().split())
    ans1,ans2=m//p,m//p+(m//p*c//f)
    start=ans1*c
    if start>=f:
        ans1+=(start-f)//(f-c)+1
    print(ans1-ans2)