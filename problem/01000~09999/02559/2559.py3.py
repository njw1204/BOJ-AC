n,k=map(int,input().split())
arr=[*map(int,input().split())]
left,right=0,0
ans=-(10**18)
nowSum=0
while right<n:
    if right-left<k:
        nowSum+=arr[right]
        right+=1
        if right-left==k:
            ans=nowSum
        continue
    nowSum-=arr[left]
    nowSum+=arr[right]
    left+=1
    right+=1
    ans=max(nowSum,ans)
print(ans)