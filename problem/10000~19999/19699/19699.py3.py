import itertools

def isprime(x):
    i=2
    while i*i<=x:
        if x%i==0: return False
        i+=1
    return True

n,m=map(int,input().split())
cow=[*map(int,input().split())]
ans=[]
for subcow in itertools.combinations(cow,m):
    wsum=sum(subcow)
    if isprime(wsum): ans.append(wsum)
ans=set(ans)
ans=sorted(ans)

if len(ans):
    for i in ans:
        print(i,end=" ")
else:
    print(-1)