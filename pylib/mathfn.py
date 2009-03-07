import math
from pylib import prime
import time

def fac(n):
    result = 1
    for i in range(n, 1, -1):
        result *= i
    return result

def comb(n, k):
    if k > n or n == k:
        return 0
    return fac(n) / (fac(k) * fac(n - k))

def perm(n, k):
    if k > n or n == k:
        return 0
    return fac(n) / fac(n - k)

def next_triangle_num():
    '''
    A generator function that Calculates the next
    triangle number.
    '''
    num = 1
    add_num = 2

    while 1:
        yield num
        num += add_num
        add_num += 1

def calculate_possible_factors(pf):
    '''
    calculates the number of possible factors for
    a given list of prime factors which might contain
    duplicates.

    example:
        calculate_possible_factors([2, 2, 7]) --> 5
    '''
    # it uses the formula (a_1+1) * (a_2+1) * ...
    # where p_1^a_1 * p_2^a_2 * ...
    # using a nested list works
    possible_factors = 1

    l = []

    try:
        num = pf[0]
    except IndexError:
        return 0

    l_of_l = []
    l_of_l.append(num)

    for i in range(1, len(pf)):
        if pf[i] == num:
            l_of_l.append(pf[i])
        else:
            l.append(l_of_l)
            l_of_l = []
            num = pf[i]
            l_of_l.append(num)

    l.append(l_of_l)

    for i in l:
        possible_factors *= (len(i) + 1)

    return possible_factors

if __name__ == '__main__':
    start_time = time.time()
    divisors = []

    for num in next_triangle_num():
        print num,
        divisors = []
        
        for i in prime.primes_max(int(math.sqrt(num))):
            while not num % i:
                divisors.append(i)
                num /= i

        num_divisors = calculate_possible_factors(divisors)
        print divisors, num_divisors

        if num_divisors > 500:
            print 'the number is the last number printed'
            break

    elapsed = time.time() - start_time
    print elapsed

