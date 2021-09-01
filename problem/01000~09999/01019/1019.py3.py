def count_all_characters_1_to_target(target):
    for target_digit in range(1, 11):
        if target < 10**target_digit:
            base_value = 0
            for i in range(1, target_digit):
                base_value += 9 * 10**(i-1) * i
            return base_value + (target - 10**(target_digit-1) + 1) * target_digit

def count_naive_without_zero(num):
    global ans
    while num:
        if num%10!=0:
            ans[num%10]+=1
        num//=10

def add_ans_from_pre_ans_for_digit(digit):
    global ans, pre_ans_for_digit
    for i in range(1,10):
        ans[i] += pre_ans_for_digit[digit]

def solve_without_zero(n):
    global ans

    n_str = str(n)
    n_len = len(n_str)

    for i in range(n_len):
        prefix_digits = n_str[:i+1]
        prefix_non_key_digits = prefix_digits[:-1]
        key_digit = prefix_digits[-1]
        remain_digits_len = n_len - (i + 1)
        
        for j in range(int(key_digit)):
            for k in range(1, remain_digits_len+1):
                add_ans_from_pre_ans_for_digit(k)
            now_iter_digits = prefix_non_key_digits + str(j)
            for k in now_iter_digits:
                if k != '0':
                    ans[int(k)] += 10**remain_digits_len

    count_naive_without_zero(n)


n=int(input())
ans=[0]*10
all_character_count=count_all_characters_1_to_target(n)

pre_ans_for_digit=[0]*11
for i in range(10):
    pre_ans_for_digit[i+1] = int(10**i + i * 9 * (10**(i-1)))

solve_without_zero(n)
ans[0]=all_character_count-sum(ans[1:])
print(' '.join(map(str,ans)))