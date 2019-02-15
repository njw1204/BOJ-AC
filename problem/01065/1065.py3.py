def han(i):
    if i<100: return True
    i=list(str(i))
    diff=int(i[0])-int(i[1])
    for j in range(1,len(i)-1):
        if int(i[j])-int(i[j+1])!=diff: return False
    return True

n=int(input())
ans=0
for i in range(1,n+1):
    if han(i): ans+=1
print(ans)