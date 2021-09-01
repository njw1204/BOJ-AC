while 1:
    x=input()
    if x=="0": break
    if x==x[::-1]: print("yes")
    else: print("no")