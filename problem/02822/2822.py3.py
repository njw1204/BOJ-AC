L=[]
for i in range(1,9): L.append((i,int(input())))
L=sorted(sorted(L,key=lambda x:x[1],reverse=True)[:5],key=lambda x:x[0])
print(sum(i[1] for i in L))
for i in L: print(i[0],end=' ')