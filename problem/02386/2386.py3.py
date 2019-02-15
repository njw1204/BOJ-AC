while True:
    x=input()
    if x=="#": break

    cnt=0
    for i in range(2,len(x)):
        if x[0].lower()==x[i].lower(): cnt+=1
    print(x[0], cnt)