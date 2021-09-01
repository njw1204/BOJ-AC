n=input()
a=0
c="A"
for i in n:
 a+=min(abs(ord(c)-ord(i)),26-abs(ord(c)-ord(i)))
 c=i
print(a)