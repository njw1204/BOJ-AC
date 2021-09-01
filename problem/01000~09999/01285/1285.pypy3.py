n=int(input())
f=[]
for i in range(n):
    f.append(list(input()))

final_ans=10**18
for serial in range(0,2**n):
    check=[False]*n
    idx=0
    while serial:
        if serial%2:
            check[idx]=True
        serial//=2
        idx+=1

    ans=0
    for i in range(n):
        cnt=0
        for j in range(n):
            if (f[j][i]=="H" and check[j]==False) or (f[j][i]=="T" and check[j]==True):
                cnt+=1
        ans+=min(cnt,n-cnt)
    final_ans=min(final_ans,ans)

print(final_ans)