for i in input():
 i=ord(i)-3
 if i>=ord('A'): print(chr(i),end='')
 else: print(chr(ord('Z')-(ord('A')-i)+1),end='')