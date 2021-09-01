dp=[0]*50
dp[1]=1
for i in range(2,50):
    dp[i]=dp[i-1]+dp[i-2]
dp.sort(reverse=True)
for _ in range(int(input())):
    x=int(input())
    ans=[]
    for i in dp:
        if x>=i:
            x-=i
            ans.append(i)
        if x==0: break
    ans.sort()
    for i in ans: print(i, end=' ')
    print()