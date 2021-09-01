n=int(input())
left,right=[],[]
x1,x2=[],[]
for i in range(n):
    x=int(input())
    if x<=0: left.append(x)
    else: right.append(x)
left.sort()
right.sort(reverse=True)
nextPos=0
for i in range(0,len(left)-1,2):
    x1.append(left[i]*left[i+1])
    nextPos=i+2
for i in range(nextPos,len(left)):
    x1.append(left[i])
nextPos=0
for i in range(0,len(right)-1,2):
    if right[i+1]==1:
        break
    x2.append(right[i]*right[i+1])
    nextPos=i+2
for i in range(nextPos,len(right)):
    x2.append(right[i])
print(sum(x1)+sum(x2))