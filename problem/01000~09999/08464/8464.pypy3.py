import itertools

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

ss=[]
for i in range(2,1000001):
    if sosu[i] and i*i<=1000000000000:
        ss.append(i*i)

target=int(input())
left,right=1,1000000000000
while left<right:
    cnt=0
    mid=(left+right)//2

    for val in ss:
        if val>mid: break
        cnt+=mid//val

    lenss=len(ss)

    for i1 in range(lenss):
        s1=True
        for i2 in range(i1+1,lenss):
            val=ss[i1]*ss[i2]
            if val>mid: break
            cnt+=(mid//val)*(-1)
            s1=False
        if s1: break

    for i1 in range(lenss):
        s1=True
        for i2 in range(i1+1,lenss):
            s2=True
            for i3 in range(i2+1,lenss):
                val=ss[i1]*ss[i2]*ss[i3]
                if val>mid: break
                cnt+=(mid//val)
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
                    val=ss[i1]*ss[i2]*ss[i3]*ss[i4]
                    if val>mid: break
                    cnt+=(mid//val)*(-1)
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
                        val=ss[i1]*ss[i2]*ss[i3]*ss[i4]*ss[i5]
                        if val>mid: break
                        cnt+=(mid//val)
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
                            val=ss[i1]*ss[i2]*ss[i3]*ss[i4]*ss[i5]*ss[i6]
                            if val>mid: break
                            cnt+=(mid//val)*(-1)
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

    if cnt<target:
        left=mid+1
    elif cnt>target:
        right=mid-1
    else:
        sqfree=True
        for v in ss:
            if v>mid: break
            if mid%v==0:
                sqfree=False
                break
        if not sqfree:
            left=right=mid
            break
        else:
            right=mid-1

print(left)