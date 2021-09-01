n=int(input())
visit=set()
visit.add(n)
while True:
    sum=0
    tn=n
    while tn:
        sum+=(tn%10)*(tn%10)
        tn//=10
    n=sum
    if n==1:
        print("HAPPY")
        exit(0)
    if n in visit:
        print("UNHAPPY")
        exit(0)
    visit.add(n)