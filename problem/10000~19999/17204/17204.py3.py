x=input()
if x!=x.strip(): exit(-1)

n,k=map(int,x.split())
if not (3 <= n <= 150): exit(-1)
if not (1 <= k <= n-1): exit(-1)

res=[]
for i in range(n):
    x=input()
    if x!=x.strip(): exit(-1)
    if not (0 <= int(x) <= n-1): exit(-1)
    res.append(int(x))

succ=False
try: input()
except: succ=True
if not succ: exit(-1)

visit=[0]*n
pos=0
m=0

while True:
    m+=1
    visit[pos]=1
    nextPos=res[pos]
    if nextPos==k:
        break
    elif visit[nextPos]:
        m=-1
        break
    pos=nextPos

print(m)