t=int(input())
if not (1 <= t <= 100000): exit(-1)
dp=[0]*100001
dp[3]=3
for i in range(4,100001):
    if i%3==0 or i%7==0: dp[i]=i
    dp[i]+=dp[i-1]

query=[*map(int,input().split())]

if len(query)!=t: exit(-1)
for i in query:
    if not (10 <= int(i) <= 80000): exit(-1)
    print(dp[int(i)])

succ=False
try: input()
except: succ=True
if not succ: exit(-1)