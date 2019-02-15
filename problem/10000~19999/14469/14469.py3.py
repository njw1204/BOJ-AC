n=int(input())
x=[]
for i in range(n):
    x.append([*map(int,input().split())])
x.sort()

nt=0
for i in x:
    nt=max(nt,i[0])
    nt+=i[1]

print(nt)