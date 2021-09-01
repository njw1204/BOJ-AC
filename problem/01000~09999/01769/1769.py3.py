I,ㅣ=input(),0
l=int(I) if len(I)<2 else 0
while len(I)>1:
 ㅣ+=1
 l=0
 for I in I: l+=int(I)
 I=str(l)
print(ㅣ)
print('NO' if l%3 else 'YES')