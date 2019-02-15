u,n=map(int,input().split())
cnt=dict()
people=[[] for i in range(u+1)]
for i in range(n):
 name,price=input().split()
 price=int(price)
 cnt[price]=cnt.get(price,0)+1
 people[price].append(name)
result=sorted(cnt.items(),key=lambda x:(x[1],x[0]))[0][0]
print(people[result][0],result)