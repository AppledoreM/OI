t = int(input())
caseCnt = 0

while t > 0:
    res = 0
    n = int(input())
    inputLine = input()
    arr = [int(x) for x in inputLine.split(" ")]
    caseCnt = caseCnt + 1
    for i in range(1, n):
        now = arr[i]
        prev = arr[i - 1] + 1
        if len(str(now)) == len(str(prev)) and now < prev:
            res = res + 1
            arr[i] = arr[i] * 10
            continue
        
        addCnt = len(str(prev)) - len(str(now))
        if addCnt > 0 and now < prev:
            prevRem = prev // pow(10, addCnt)
            prevRem = prevRem * pow(10, addCnt)
            val = now * pow(10, addCnt)
            if val > prevRem:
                arr[i] = val
                res = res + addCnt
            elif val == prevRem:
                arr[i] = val
                arr[i] += prev % pow(10, addCnt)
                res = res + addCnt
            else:
                arr[i] = val * 10
                res = res + addCnt + 1
    print("Case #" + str(caseCnt) + ": " + str(res))
    t = t - 1