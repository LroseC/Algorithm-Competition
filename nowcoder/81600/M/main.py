def gcd(a, b):
    while b != 0:
        a, b = b, a
        b = b % a
    return a

def add(x, y, a, b):
    d = gcd(y, b)
    mom = y // d * b
    son = x * (b // d) + a * (y // d)
    return (son, mom)
def add2(u, v):
    return add(u[0], u[1], v[0], v[1])
def dec2(u, v):
    return add(u[0], u[1], -v[0], v[1])

def mul(x, y, a, b):
    son = x * a
    mom = y * b
    d = gcd(son, mom)
    return (son // d, mom // d)
def mul2(u, v):
    return mul(u[0], u[1], v[0], v[1])
def div2(u, v):
    return mul(u[0], u[1], v[1], v[0])

def smaller(x, y, a, b):
    d = gcd(y, b)
    return x * (b // d) < a * (y // d)
def smaller2(u, v):
    return smaller(u[0], u[1], v[0], v[1])

def my_max(x, y, a, b):
    return (a, b) if smaller(x, y, a, b) else (x, y)
def my_max2(u, v):
    return my_max(u[0], u[1], v[0], v[1])



C = [[0 for i in range(1001)] for j in range(1001)]
C[0][0] = 1
for i in range(1, 1001):
    C[i][0] = 1
    for j in range(1, i + 1):
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j]



tt = int(input())

while tt > 0:
    tt -= 1
    c, a, b = map(int, input().split())
    if a < b - a:
        a = b - a
    p = (a, b)
    dp = (b - a, b)
    pow_p = [(1, 1) for i in range(c + 1)]
    pow_dp = [(1, 1) for i in range(c + 1)]
    for i in range(1, c + 1):
        pow_p[i] = mul2(pow_p[i - 1], p)
        pow_dp[i] = mul2(pow_dp[i - 1], dp)

    res = (c, 2)
    p0 = [[(0, 1) for i in range(1001)] for j in range(1001)]
    p1 = [[(0, 1) for i in range(1001)] for j in range(1001)]
    f = [[(0, 1) for i in range(1001)] for j in range(1001)]
    for i in range(0, c):
        tmp = (0, 1)
        for j in range(0, i + 1):
            p1[i][j] = mul2(mul2((C[i][j], 1), pow_p[j]), pow_dp[i - j])
            p0[i][j] = mul2(mul2((C[i][j], 1), pow_dp[j]), pow_p[i - j])
            if p1[i][j][0] == 0 or p0[i][j][0] == 0:
                print(tt, i, j)

    i = c - 1
    while i >= 0:
        for j in range(i // 2 + 1, i + 1):
            proper = div2(p1[i][j], add2(p1[i][j], p0[i][j]));
            iproper = dec2((1, 1), proper)
            f[i][j] = (c, 1)
            f[i][i - j] = (0, 1);

            tmp1 = mul2(f[i + 1][j + 1], p)
            tmp0 = mul2(f[i + 1][i - j], dp)
            tmp1 = add2(tmp1, mul2(f[i + 1][j], dp))
            tmp0 = add2(tmp0, mul2(f[i + 1][i - j + 1], p))
            sum_n = add2(mul2(iproper, tmp0), mul2(proper, tmp1));
            sum_o = add2(mul2(proper, f[i][j]), mul2(iproper, f[i][i - j]))
            if smaller2(sum_o, sum_n):
                f[i][j] = tmp1
                f[i][i - j] = tmp0

        j = i // 2
        if j * 2 == i:
            proper = (1, 2)
            iproper = (1, 2)
            f[i][j] = (c // gcd(c, 2), 2 // gcd(c, 2))

            tmp1 = mul2(f[i + 1][j + 1], p)
            tmp0 = mul2(f[i + 1][i - j], dp)
            tmp1 = add2(tmp1, mul2(f[i + 1][j], dp))
            tmp0 = add2(tmp0, mul2(f[i + 1][i - j + 1], p))
            sum_n = add2(mul2(iproper, tmp0), mul2(proper, tmp1));
            sum_o = f[i][j]
            if smaller2(sum_o, sum_n):
                f[i][j] = sum_n

        i -= 1
    print("%d/%d" % (f[0][0][0], f[0][0][1]))
