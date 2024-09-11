def buildSA(n):
    x = [0 for i in range(n)]
    y = [0 for i in range(n)]
    sa = [0 for i in range(n + 1)]
    m = 200
    for i in range(n):
        x[i] = ord(str[i])
        y[i] = i
    indexSort(m, sa, x, y)
    k = 1
    while k <= n and m != n:
        num = 0
        for i in range(n - k, n):
            y[num] = i
            num += 1
        for i in range(1, n + 1):
            if sa[i] >= k:
                y[num] = sa[i] - k
                num += 1
        indexSort(m, sa, x, y)
        num = 1
        x, y = y, x
        for i in range(1, n + 1):
            y1 = y[sa[i] + k] if sa[i] + k < n else 0
            y2 = y[sa[i - 1] + k] if sa[i - 1] + k < n else 0
            if i != 1 and (y[sa[i]] != y[sa[i - 1]] or y1 != y2):
                num += 1
            x[sa[i]] = num
        k = k * 2
        m = num
    return sa
def indexSort(m, sa, x, y):
    c = [0 for i in range(m + 1)]
    for i in range(n):
        c[x[y[i]]] += 1
    for i in range(1, m + 1):
        c[i] += c[i - 1]
    for i in range(n - 1, -1, -1):
        sa[c[x[y[i]]]] = y[i]
        c[x[y[i]]] -= 1;


str = input()
n = len(str)
sa = buildSA(n)
for i in range(1, n + 1):
    print(sa[i] + 1, end = ' ')
print('')
