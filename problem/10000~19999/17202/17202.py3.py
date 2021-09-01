x,y=input(),input()
if x!=x.strip() or len(x)!=8: exit(-1)
if y!=y.strip() or len(y)!=8: exit(-1)
if x==y:
   while 1:0
for i in range(7): 0
succ=False
try: input()
except: succ=True
if not succ: exit(-1)

r=[]

for i in range(16):
    if i%2==0:
        r.append(int(x[i//2]))
    else:
        r.append(int(y[i//2]))

while len(r)>2:
    temp=[]
    for i in range(len(r)-1):
        temp.append((r[i]+r[i+1])%10)
    # print(temp)
    r=temp[:]

print(str(r[0])+str(r[1]))