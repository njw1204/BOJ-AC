dict1=dict()
dict2=dict()

n,m=map(int,input().split())
for i in range(n):
    team=input()
    dict1[team]=set()
    for j in range(int(input())):
        x=input()
        dict1[team].add(x)
        dict2[x]=team
for i in range(m):
    x=input()
    if int(input())==0:
        for j in sorted(dict1[x]):
            print(j)
    else:
        print(dict2[x])