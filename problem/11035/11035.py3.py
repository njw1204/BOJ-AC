while True:
    try:
        n,k=map(int,input().split())
        sosu=[1]*(n+1)
        cnt=0
        i=2
        while i<=n and cnt<k:
            if sosu[i]==0:
                i+=1
                continue
            cnt+=1
            if cnt==k:
                print(i)
                break
            j=i*2
            while j<=n:
                if sosu[j]==1:
                    sosu[j]=0
                    cnt+=1
                if cnt==k:
                    print(j)
                    break
                j+=i
            i+=1
    except: break