import sys

n=1000000
sosu=[True]*(n+5)
sosu[1],sosu[2]=False,True
i=2
while i*i<=n:
    if sosu[i]==False:
        i+=1
        continue
    j=i*i
    while j<=n:
        sosu[j]=False
        j+=i
    i+=1

N,P=map(int,input().split())
if N==1:
    print(P)
    sys.exit()
if P*P>10**9:
    print(0)
    sys.exit()

ss=[]
for i in range(2,n+1):
    if sosu[i] and i<P:
        ss.append(i)

left,right=1,10**9+1
while left<right:
    cnt=cnt2=0
    mid=(left+right)//2
    lenss=len(ss)

    for val in ss:
        if val*P>mid: break
        cnt2+=mid//(val*P)

    for i1 in range(lenss):
        s1=True
        for i2 in range(i1+1,lenss):
            val=ss[i1]*ss[i2]*P
            if val>mid: break
            cnt2+=(mid//val)*(-1)
            s1=False
        if s1: break

    for i1 in range(lenss):
        s1=True
        for i2 in range(i1+1,lenss):
            s2=True
            for i3 in range(i2+1,lenss):
                val=ss[i1]*ss[i2]*ss[i3]*P
                if val>mid: break
                cnt2+=mid//val
                s2=False
            if s2: break
            s1=False
        if s1: break

    for i1 in range(lenss):
        s1=True
        for i2 in range(i1+1,lenss):
            s2=True
            for i3 in range(i2+1,lenss):
                s3=True
                for i4 in range(i3+1,lenss):
                    val=ss[i1]*ss[i2]*ss[i3]*ss[i4]*P
                    if val>mid: break
                    cnt2+=(mid//val)*(-1)
                    s3=False
                if s3: break
                s2=False
            if s2: break
            s1=False
        if s1: break

    for i1 in range(lenss):
        s1=True
        for i2 in range(i1+1,lenss):
            s2=True
            for i3 in range(i2+1,lenss):
                s3=True
                for i4 in range(i3+1,lenss):
                    s4=True
                    for i5 in range(i4+1,lenss):
                        val=ss[i1]*ss[i2]*ss[i3]*ss[i4]*ss[i5]*P
                        if val>mid: break
                        cnt2+=mid//val
                        s4=False
                    if s4: break
                    s3=False
                if s3: break
                s2=False
            if s2: break
            s1=False
        if s1: break

    for i1 in range(lenss):
        s1=True
        for i2 in range(i1+1,lenss):
            s2=True
            for i3 in range(i2+1,lenss):
                s3=True
                for i4 in range(i3+1,lenss):
                    s4=True
                    for i5 in range(i4+1,lenss):
                        s5=True
                        for i6 in range(i5+1,lenss):
                            val=ss[i1]*ss[i2]*ss[i3]*ss[i4]*ss[i5]*ss[i6]*P
                            if val>mid: break
                            cnt2+=(mid//val)*(-1)
                            s5=False
                        if s5: break
                        s4=False
                    if s4: break
                    s3=False
                if s3: break
                s2=False
            if s2: break
            s1=False
        if s1: break
    
    for i1 in range(lenss):
        s1=True
        for i2 in range(i1+1,lenss):
            s2=True
            for i3 in range(i2+1,lenss):
                s3=True
                for i4 in range(i3+1,lenss):
                    s4=True
                    for i5 in range(i4+1,lenss):
                        s5=True
                        for i6 in range(i5+1,lenss):
                            s6=True
                            for i7 in range(i6+1,lenss):
                                val=ss[i1]*ss[i2]*ss[i3]*ss[i4]*ss[i5]*ss[i6]*ss[i7]*P
                                if val>mid: break
                                cnt2+=mid//val
                                s6=False
                            if s6: break
                            s5=False
                        if s5: break
                        s4=False
                    if s4: break
                    s3=False
                if s3: break
                s2=False
            if s2: break
            s1=False
        if s1: break
    
    for i1 in range(lenss):
        s1=True
        for i2 in range(i1+1,lenss):
            s2=True
            for i3 in range(i2+1,lenss):
                s3=True
                for i4 in range(i3+1,lenss):
                    s4=True
                    for i5 in range(i4+1,lenss):
                        s5=True
                        for i6 in range(i5+1,lenss):
                            s6=True
                            for i7 in range(i6+1,lenss):
                                s7=True
                                for i8 in range(i7+1,lenss):
                                    val=ss[i1]*ss[i2]*ss[i3]*ss[i4]*ss[i5]*ss[i6]*ss[i7]*ss[i8]*P
                                    if val>mid: break
                                    cnt2+=(mid//val)*(-1)
                                    s7=False
                                if s7: break
                                s6=False
                            if s6: break
                            s5=False
                        if s5: break
                        s4=False
                    if s4: break
                    s3=False
                if s3: break
                s2=False
            if s2: break
            s1=False
        if s1: break
        
    for i1 in range(lenss):
        s1=True
        for i2 in range(i1+1,lenss):
            s2=True
            for i3 in range(i2+1,lenss):
                s3=True
                for i4 in range(i3+1,lenss):
                    s4=True
                    for i5 in range(i4+1,lenss):
                        s5=True
                        for i6 in range(i5+1,lenss):
                            s6=True
                            for i7 in range(i6+1,lenss):
                                s7=True
                                for i8 in range(i7+1,lenss):
                                    s8=True
                                    for i9 in range(i8+1,lenss):
                                        val=ss[i1]*ss[i2]*ss[i3]*ss[i4]*ss[i5]*ss[i6]*ss[i7]*ss[i8]*ss[i9]*P
                                        if val>mid: break
                                        cnt2+=mid//val
                                        s8=False
                                    if s8: break
                                    s7=False
                                if s7: break
                                s6=False
                            if s6: break
                            s5=False
                        if s5: break
                        s4=False
                    if s4: break
                    s3=False
                if s3: break
                s2=False
            if s2: break
            s1=False
        if s1: break

    cnt=mid//P-cnt2
    if cnt<N:
        left=mid+1
    elif cnt>N:
        right=mid-1
    else:
        ans=True
        for v in ss:
            if mid%v==0:
                ans=False
                break
        if ans and mid%P==0:
            left=right=mid
            break
        else:
            right=mid-1

print(left if left<=10**9 else 0)