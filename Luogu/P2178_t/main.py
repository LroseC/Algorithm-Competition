import sys
sys.setrecursionlimit(500000)
def indexSort(n, m, x, y, sa):
    c = [0 for i in range(m + 1)]
    for i in range(n):
        c[x[y[i]]] += 1
    for i in range(m):
        c[i + 1] += c[i]
    for i in range(n - 1, -1, -1):
        c[x[y[i]]] -= 1
        sa[c[x[y[i]]]] = y[i]
def buildSA(n):
    x = [0 for i in range(n)]
    y = [0 for i in range(n)]
    sa = [0 for i in range(n)]
    rk = [0 for i in range(n)]
    height = [0 for i in range(n)]

    for i in range(n):
        y[i] = i
        x[i] = ord(s[i])
    m = 200
    indexSort(n, m, x, y, sa)

    k = 1
    while k < n:
        num = 0
        for i in range(n - k, n):
            y[num] = i
            num += 1
        for i in range(n):
            if sa[i] - k >= 0:
                y[num] = sa[i] - k
                num += 1
        indexSort(n, m, x, y, sa)
        x, y = y, x
        x[sa[0]] = 1
        for i in range(1, n):
            y1 = y[sa[i] + k] if sa[i] + k < n else -1
            y2 = y[sa[i - 1] + k] if sa[i - 1] + k < n else -1
            x[sa[i]] = x[sa[i - 1]] + int(y[sa[i]] != y[sa[i - 1]] or y1 != y2)
        m = x[sa[n - 1]]
        if m == n:
            break
        k *= 2

    for i in range(n):
        rk[sa[i]] = i
    for i in range(n):
        l = height[rk[i - 1]] - 1 if i != 0 else 0
        l = 0 if l < 0 else l
        j = sa[rk[i] - 1]
        pos = i if i > j else j
        while pos + l < n and s[i + l] == s[j + l]:
            l += 1
        height[rk[i]] = l
    return sa, rk, height

def buildST():
    global st
    global lg2
    global height
    lg2 = [0 for i in range(n + 1)]
    for i in range(2, n + 1):
        lg2[i] = lg2[i >> 1] + 1
    st = [[i for i in range(n)] for j in range(lg2[n] + 1)]
    for k in range(1, lg2[n] + 1):
        for i in range(n - (1 << k) + 1):
            if height[st[k - 1][i]] < height[st[k - 1][i + (1 << k - 1)]]:
                st[k][i] = st[k - 1][i]
            else:
                st[k][i] = st[k - 1][i + (1 << k - 1)]

def queryST(l, r):
    global st
    global lg2
    global height
    t = lg2[r - l + 1]
    if height[st[t][l]] < height[st[t][r - (1 << t) + 1]]:
        return st[t][l]
    else:
        return st[t][r - (1 << t) + 1]

def merge(x, y):
    return (max(x[0], y[0]), max(x[1], y[1]))

def solve(l, r):
    global a
    if l == r:
        return (-1, -a[sa[l]]) if a[sa[l]] < 0 else (a[sa[l]], -1)
    if l > r:
        return 0
    global height
    global ansSum
    global ansMax
    pos = queryST(l + 1, r)
    ansSum[height[pos]] += (pos - l) * (r - pos + 1)
    left = solve(l, pos - 1)
    right = solve(pos, r)
    if left[0] != -1 and right[0] != -1:
        if left[0] * right[0] > ansMax[height[pos]]:
            ansMax[height[pos]] = left[0] * right[0]
    if left[1] != -1 and right[1] != -1:
        if left[1] * right[1] > ansMax[height[pos]]:
            ansMax[height[pos]] = left[1] * right[1]
    if left[0] != -1 and right[1] != -1:
        if -left[0] * right[1] > ansMax[height[pos]]:
            ansMax[height[pos]] = -left[0] * right[1]
    if left[1] != -1 and right[0] != -1:
        if -left[1] * right[0] > ansMax[height[pos]]:
            ansMax[height[pos]] = -left[1] * right[0]
    return merge(left, right)

n = int(input())
s = input()
a = [int(i) for i in input().split()]
sa, rk, height = buildSA(n)
buildST()
ansSum = [0 for i in range(n)]
ansMax = [-0x3f3f3f3f3f3f3f3f for i in range(n)]
solve(0, n - 1)
for i in range(n - 1, 0, -1):
    ansSum[i - 1] += ansSum[i]
    ansMax[i - 1] = ansMax[i] if ansMax[i] > ansMax[i - 1] else ansMax[i - 1]
for i in range(n):
    print(ansSum[i], ansMax[i] if ansMax[i] != -0x3f3f3f3f3f3f3f3f else 0)
