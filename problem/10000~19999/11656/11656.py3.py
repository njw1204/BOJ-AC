x=input()[::-1]
r=[]
for i in range(len(x)):
 r.append((x[:i+1])[::-1])
r.sort()
for i in r: print(i)