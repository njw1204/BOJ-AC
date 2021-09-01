from functools import cmp_to_key
alpha_order = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"

def is_num_char(ch):
    return (ord(ch) >= ord('0') and ord(ch) <= ord('9'))

def count_leading_zero(x):
    c = 0
    for i in x:
        if i == "0": c += 1
        else: return c
    return c

def parsestr(x):
    parsed_list = []
    temp = ""
    for i in x:
        if is_num_char(i):
            temp += i
        else:
            if temp: parsed_list.append(temp)
            parsed_list.append(i)
            temp = ""
    if temp: parsed_list.append(temp)
    return parsed_list

def comp_numstr(x,y):
    if int(x) != int(y):
        return int(x) - int(y)
    elif count_leading_zero(x) != count_leading_zero(y):
        return count_leading_zero(x) - count_leading_zero(y)
    else:
        return 0

def comp(x,y):
    x = parsestr(x)
    y = parsestr(y)
    for i in range(min(len(x), len(y))):
        if is_num_char(x[i][0]) != is_num_char(y[i][0]):
            return is_num_char(y[i][0]) - is_num_char(x[i][0])
        elif is_num_char(x[i][0]) and is_num_char(y[i][0]):
            res = comp_numstr(x[i], y[i])
            if res: return res
        else:
            res = alpha_order.index(x[i]) - alpha_order.index(y[i])
            if res: return res
    if len(x) == len(y) == min(len(x), len(y)): return 0
    else: return len(x) - len(y)

n = int(input())
x = [input() for i in range(n)]
x.sort(key=cmp_to_key(comp))
for i in x: print(i)