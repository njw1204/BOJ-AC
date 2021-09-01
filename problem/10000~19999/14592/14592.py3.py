x=[]
for i in range(int(input())):
    s,c,l=map(int,input().split())
    x.append([s,-c,-l,i+1])
x.sort(reverse=True)
print(x[0][3])