import sys,math
input=sys.stdin.readline
while 1:
 x=int(input())
 if x<1: break
 if math.gcd(x,6)>1: print("Kralovny se nevejdou.")
 else: print("Kralovny lze umistit.")