s=input()
c=0
r=[]
for _ in range(int(input())):
    x=input()
    fail=False
    for i in range(9):
        if s[i]!=x[i] and s[i]!="*":
            fail=True
            break
    if not fail:
        c+=1
        r.append(x)

print(c)
for i in r: print(i)