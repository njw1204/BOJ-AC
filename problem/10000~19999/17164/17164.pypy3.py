n=int(input())
x=input()
ans=1

tempAns=0
pos=0
while pos<n:
    if x[pos]=="V":
        tempAns=0
        pos+=1
    else:
        if tempAns==0 or x[pos-1]!=x[pos]:
            tempAns+=1
            ans=max(ans,tempAns)
            pos+=1
        else:
            tempAns=0

print(ans)