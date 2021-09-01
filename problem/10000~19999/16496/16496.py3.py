import functools
def s(x,y): return int(y+x)-int(x+y)
input();print(int("".join(sorted(input().split(),key=functools.cmp_to_key(s)))))