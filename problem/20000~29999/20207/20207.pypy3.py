number_of_schedule = [[0 for j in range(444)] for i in range(444)]
is_filled = [[0 for j in range(444)] for i in range(1111)]
date_height = [0 for i in range(444)]

n = int(input())
for i in range(n):
    s, e = map(int, input().split())
    number_of_schedule[s][e] += 1

for schedule_start_day in range(1, 366):
    for schedule_end_day in range(365, schedule_start_day - 1, -1):
        while number_of_schedule[schedule_start_day][schedule_end_day]:
            for position in range(1, n + 1):
                if max(is_filled[position][schedule_start_day:schedule_end_day + 1]) == 0:
                    for i in range(schedule_start_day, schedule_end_day + 1):
                        is_filled[position][i] = 1
                    break
            number_of_schedule[schedule_start_day][schedule_end_day] -= 1

for position in range(1, n + 1):
    for day in range(1, 366):
        if is_filled[position][day]:
            date_height[day] = max(date_height[day], position)

ans = 0
curr_width = curr_height = 0
for i in range(1, 366):
    if date_height[i] == 0:
        ans += curr_width * curr_height
        curr_width = curr_height = 0
    else:
        curr_width += 1
        curr_height = max(curr_height, date_height[i])
ans += curr_width * curr_height
print(ans)