n = int(input())
k = 1
for i in range(n):
	for j in range(n - i):
		print("%02d" % k, end='')
		k += 1
	print('')
