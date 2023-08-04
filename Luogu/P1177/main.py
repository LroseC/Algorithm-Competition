import random

def qsort(val, l, r):
	if (l >= r):
		return
	md = val[random.randint(l, r)]
	le = l
	m = l
	ri = r
	while (m <= ri):
		if val[m] < md:
			val[le], val[m] = val[m], val[le]
			m += 1
			le += 1
		elif val[m] > md:
			val[m], val[ri] = val[ri], val[m]
			ri -= 1
		else:
			m += 1
	qsort(val, l, le - 1)
	qsort(val, ri + 1, r)

n = int(input())
val = [int(x) for x in input().split()]
qsort(val, 0, n - 1)
for i in range(n):
	print(val[i], end = ' ')
print('')