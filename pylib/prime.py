import math

def is_prime(num):
    if num < 2:         return False
    elif num < 4:       return True
    elif not num % 2:   return False
    elif num < 9:       return True
    elif not num % 3:   return False
    else:
        for n in range(5, int(math.sqrt(num) + 1), 6):
            if not num % n:
                return False
            elif not num % (n + 2):
                return False

    return True

def primes_max(max):
    yield 2
    for n in range(3, max, 2):
        if is_prime(n):
            yield n

def primes_count(count):
    counter = 0
    num = 3

    yield 2

    while counter < count:
        if is_prime(num):
            yield num
            counter += 1
        num += 2

# unit test 
if __name__ == '__main__':
    print 'printing prime numbers up to 60:'
    for i in primes_max(60):
        print i,

    print '\nprinting the first 20 prime numbers:'
    for i in primes_count(20):
        print i,
