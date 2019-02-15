x=[]
n=input()
for i in range(1,int(n)+1):
 x.append(str(i))
print(''.join(x).find(n)+1)