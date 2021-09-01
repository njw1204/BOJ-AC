i=2
while True:
 n=input()
 if n=="Was it a cat I saw?": break
 for s in range(0,len(n),i): print(end=n[s])
 print()
 i+=1