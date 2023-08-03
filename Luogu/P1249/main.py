n = int(input())
i = 2
a = []
while i <= n:
	a.append(i)
	n -= i
	i = i + 1

ln = len(a)
while n > 0:
	a[ln - 1] += 1
	n -= 1
	ln -= 1
res = 1
for x in a:
	print(x, end = ' ')
	res *= x;
print('')
print(res)