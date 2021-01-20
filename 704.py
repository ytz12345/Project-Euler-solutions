# python3

# 0
# 1 0
# 2 1 2 0
# 3 2 3 1 3 2 3 0

def S(n):
    if n <= 1: return 0
    sum_of_all_line = 0
    sum_of_last_line = 0
    line, count = 1, 1
    while count + (1 << line) <= n:
        sum_of_last_line = sum_of_last_line * 2 + (1 << line) - 1
        sum_of_all_line += sum_of_last_line

        count += 1 << line
        line += 1
    
    if count == n: return sum_of_all_line
    
    n -= count
    ans = sum_of_all_line

    now_pos = 1 << (line - 1)
    now_sum = sum_of_last_line + now_pos - 1
    now_val = 1

    while n != 0:
        if n == now_pos:
            ans += now_sum + now_val
            break
        else:
            if n > now_pos:
                n -= now_pos
                ans += now_sum + now_val
            now_pos >>= 1
            now_val += 1
        now_sum = (now_sum - now_val) >> 1
    
    return ans
        
print(S(int(input())))
