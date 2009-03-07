for i in range(999, 700, -1):
	for j in range(i - 1, 700, -1):
		s = str(i * j)
		if s[0] == s[-1] and s[1] == s[-2] and s[2] == s[-3]:
			print i, j, s
