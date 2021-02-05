import random

n, sides, card_num, double_times_to_jail = 40, 4, 16, 3
go_pos, jail_pos, g2j_pos, c1_pos, e3_pos, h2_pos, r1_pos = 0, 10, 30, 11, 24, 39, 5
cc_pos, ch_pos, r_pos, u_pos = [2, 17, 33], [7, 22, 36], [5, 15, 25, 35, 45], [12, 28, 52]
cc_go, cc_jail = 1, 2
ch_go, ch_jail, ch_c1, ch_e3, ch_h2, ch_r1, ch_next_r, ch_next_u, ch_back_3 = 1, 2, 3, 4, 5, 6, [7, 8], 9, 10

cnt = [0 for i in range(n)]
now_pos, double_times, rounds_limit = 0, 0, 1000000

for i in range(rounds_limit):
    r1, r2 = random.randint(1, sides), random.randint(1, sides)
    now_pos = (now_pos + r1 + r2) % n
    if r1 == r2:
        double_times += 1
    else:
        double_times = 0

    if now_pos in cc_pos:
        r3 = random.randint(1, card_num)
        if r3 == cc_go: 
            now_pos = go_pos
        elif r3 == cc_jail:
            now_pos = jail_pos

    elif now_pos in ch_pos:
        r4 = random.randint(1, card_num)
        if r4 == ch_go:
            now_pos = go_pos
        elif r4 == ch_jail:
            now_pos = jail_pos
        elif r4 == ch_c1:
            now_pos = c1_pos
        elif r4 == ch_e3:
            now_pos = e3_pos
        elif r4 == ch_h2:
            now_pos = h2_pos
        elif r4 == ch_r1:
            now_pos = r1_pos
        elif r4 in ch_next_r:
            for pos in r_pos:
                if pos > now_pos:
                    now_pos = pos % n
                    break
        elif r4 == ch_next_u:
            for pos in u_pos:
                if pos > now_pos:
                    now_pos = pos % n
                    break
        elif r4 == ch_back_3:
            now_pos -= 3

    elif now_pos == g2j_pos:
        now_pos = jail_pos

    if double_times == double_times_to_jail: 
        now_pos = jail_pos
        double_times = 0

    cnt[now_pos] += 1

threshold = int(rounds_limit * 0.0309)
for i in range(n):
    if cnt[i] > threshold:
        print(i, cnt[i])