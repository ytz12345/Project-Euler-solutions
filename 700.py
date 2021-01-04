a, b = 1504170715041707, 4503599627370517
sm = 1513083232796311
arr = [[1, a], [3, a * 3 - b]]

for i in range(100):
    k = 2
    while True:
        if (arr[-1][0] * k - arr[-2][0]) * a % b < arr[-1][1]:
            arr.append([arr[-1][0] * k - arr[-2][0], (arr[-1][0] * k - arr[-2][0]) * a % b])
            sm += arr[-1][1]
            break
        k += 1
    print(arr[-1], sm)