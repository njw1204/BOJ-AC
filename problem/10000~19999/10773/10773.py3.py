x=[]
for i in range(int(input())):
 n=int(input())
 if n: x.append(n)
 else: x.pop()
print(sum(x))