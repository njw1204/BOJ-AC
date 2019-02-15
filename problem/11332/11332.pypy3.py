import math
C = int(input())
while(C>0):
    S, N, T, L= input().split()
    tl = int(L) * 100000000
    if(S=="O(N)"):
        o = int(N) * int(T)
    elif(S=="O(N^2)"):
        o = (int(N) ** 2) * int(T)
    elif(S=="O(N^3)"):
        o = (int(N) ** 3) * int(T)
    elif(S=="O(2^N)"):
    	o = int(T)
    	for i in range(int(N)):
    		o *= 2
    		if o>tl:
    			break
    else:
        o = math.factorial(int(N))
        o *= int(T)
    if(o>tl):
        print("TLE!")
    else:
        print("May Pass.")
    C-=1
    
    
  