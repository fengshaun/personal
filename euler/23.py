import time
import math

def divisors(n):
    div = [1]
    sum = 1
    high_bound = int(math.sqrt(n))
    if high_bound * high_bound == n:
        # perfect square
        div.append(high_bound)
        high_bound -= 1

    for i in range(2, high_bound + 1):
        if not n % i:
            div.append(i)
            div.append(n / i)
            sum += i + n / i
    return (div, sum)

def sum_of_divisors(n):
    sum = reduce((lambda x, y: x + y), divisors(n))
    return sum

def is_perfect_num(n):
    return True if n == sum_of_divisors(n) else False

def is_abundant_num(n):
    return True if n < divisors(n)[1] else False

def is_deficient_num(n):
    return True if n > sum_of_divisors(n) else False

def can_sum_abundant(n):
    # 12 is the first abundant number and 13 is prime
    for i in range(12, n // 2 + 1):
        if is_abundant_num(i) and is_abundant_num(n - i):
                # both are abundant
                return True
    return False
                        

if __name__ == '__main__':
    start = time.time()
    sum = 0
    for i in range(24, 28124):
        if not can_sum_abundant(i):
            print i
            sum += i

    elapsed = time.time() - start
    print sum, '\ntook: %ss' % elapsed
        
