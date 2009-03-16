import time
import math

def divisors(n):
    div = [1]
    high_bound = int(math.sqrt(n))
    if high_bound * high_bound == n:
        # perfect square
        div.append(high_bound)
        high_bound -= 1

    for i in range(2, high_bound + 1):
        if n % i == 0:
            div.append(i)
            div.append(n // i)
    return div

def sod(n):
    sum = 1
    high_bound = int(math.sqrt(n))
    if high_bound * high_bound == n:
        # perfect square
        sum += high_bound
        high_bound -= 1

    for i in range(2, high_bound + 1):
        if n % i == 0:
            sum += i + n // i
    return sum

def is_abundant(n):
    sum = 1
    high_bound = int(math.sqrt(n))
    if high_bound * high_bound == n:
        # perfect square
        sum += high_bound
        high_bound -= 1

    for i in range(2, high_bound + 1):
        if n % i == 0:
            sum += i + n // i

    if sum > n: return True
    else: return False

def sum_of_divisors(n):
    return reduce((lambda x, y: x + y), divisors(n))

def is_perfect_num(n):
    return True if n == sod(n) else False

def is_abundant_num(n):
    return True if n < sod(n) else False

def is_deficient_num(n):
    return True if n > sum_of_divisors(n) else False

def can_sum_abundant(n):
    # 12 is the first abundant number
    for i in xrange(12, n // 2 + 2):
        if is_abundant(i) and is_abundant(n - i):
            return True
    return False
                        

if __name__ == '__main__':
    start = time.time()
    sum = 0
    for i in range(1, 20162):
        if not can_sum_abundant(i):
            sum += i

    elapsed = time.time() - start
    print sum, '\ntook: %ss' % elapsed
        
