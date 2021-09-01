n=int(input())
o=0
sumt=2
while o<n:
    for i in range(sumt-1,0,-1):
        a,b=i,sumt-i
        o+=1
        if o==n:
            print(a,b)
            exit(0)
    sumt+=1