def square_of_sum(num):
	sum = 0
	for i in range(1, num + 1):
		sum += i

	return sum ** 2

def sum_of_squares(num):
	sum = 0
	for i in range(1, num + 1):
		sum += i * i

	return sum

if __name__ == '__main__':
	print sum_of_squares(100) - square_of_sum(100)
