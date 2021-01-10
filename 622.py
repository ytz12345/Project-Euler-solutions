def calc_n_ans(n):
    arr = [i for i in range(n)]
    brr = [i for i in range(n)]
    for i in range(0, n, 2): 
        arr[i // 2] = brr[i]
    for i in range(1, n, 2): 
        arr[i // 2 + n // 2] = brr[i]
    now, cnt = arr[1], 1
    while now != 1:
        now = arr[now]
        cnt += 1
    return cnt
 
''' 
for i in range(2, 10001, 2):
    if calc_n_ans(i) == 60:
        print(i)
'''